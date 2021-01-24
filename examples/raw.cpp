// ================================================

#include <iostream>
#include <fstream>
#include "raw.hpp"

using namespace std;

Raw::Raw(string filename, size_t height, size_t width, size_t bitwidth) :
  filename(filename), height(height), width(width), bitwidth(bitwidth)
{
  bool success = readVector(filename, imgvec_);
}


Raw::~Raw(void)
{
}


size_t  Raw::getFilesize(ifstream& ifs)
{
  ifs.seekg(0, std::ios::end);
  size_t filesize=ifs.tellg();
  ifs.seekg(0, std::ios::beg);
  return filesize;
}


bool Raw::readVector(string filename, vector<uint16_t>& vec)
{
  ifstream ifs(filename, std::ios::binary);
  if (!ifs) return false; // error
  size_t filesize = getFilesize(ifs);
  size_t vecsize  = filesize / sizeof(uint16_t);
  vec.resize(vecsize);
  ifs.read((char *)vec.data(), filesize);
  return (vec.size()>0);
}


bool Raw::writeVector(string filename, vector<uint16_t>& vec)
{
  ofstream ofs(filename);
  if (!ofs) return false; // error
  size_t bytesize = sizeof(uint16_t) * vec.size();
  ofs.write((char *)vec.data(), bytesize);
  return true;
}


uint16_t Raw::at(size_t idx)
{
  return imgvec_.at(idx);
}


uint16_t Raw::at(size_t row, size_t col)
{
  return imgvec_.at(row*width+col);
}


size_t Raw::size()
{
  return imgvec_.size();
}


bool Raw::save()
{
  return writeVector(filename, imgvec_);
}


bool Raw::saveas(string filename)
{
  return writeVector(filename, imgvec_);
}


// ============================================================================
// ============================================================================


#define print(a,b) std::cout << a << " " << b << endl;
#define hex(a) std::cout << std::hex << a << std::dec << " ";


int main()
{
  size_t w = 640;
  size_t h = 480;
  size_t expected_size = h * w;
  Raw raw1("bin.raw", 480, 640, 16);
  if (raw1.size()==0) {
    cout << "Error opening file '"  << raw1.filename << "'\n";
    return 1;
  } else if (raw1.size() != expected_size) {
    cout << "Error. Filesize = " << raw1.size() << " Expected size = " << expected_size << "\n";
    return 2;
  }
  
  cout << "Image Size = " << raw1.size() << " should be " << expected_size << endl;
  
  raw1.saveas("new.raw");
  
  print("width =",raw1.width)
  
  for (int r=0; r<1; r++) {
    for (int c=0; r<raw1.width; c++) {
      hex(raw1.at(r,c))
    }
    cout << endl << endl;
  }
  
  return 0;
}


