// ================================================

#include <iostream>
#include <fstream>
#include "rawvector.hpp"

using namespace std;

RawVector::RawVector(string filename, size_t height, size_t width, size_t bitwidth) :
  filename(filename), height(height), width(width), bitwidth(bitwidth)
{
  bool success = readVector(filename, imgvec_);
}


RawVector::~RawVector(void)
{
}


size_t  RawVector::getFilesize(ifstream& ifs)
{
  ifs.seekg(0, std::ios::end);
  size_t filesize=ifs.tellg();
  ifs.seekg(0, std::ios::beg);
  return filesize;
}


bool RawVector::readVector(string filename, vector<uint16_t>& vec)
{
  ifstream ifs(filename, std::ios::binary);
  if (!ifs) return false; // error
  size_t filesize = getFilesize(ifs);
  size_t vecsize  = filesize / sizeof(uint16_t);
  vec.resize(vecsize);
  ifs.read((char *)vec.data(), filesize);
  return (vec.size()>0);
}


bool RawVector::writeVector(string filename, vector<uint16_t>& vec)
{
  ofstream ofs(filename);
  if (!ofs) return false; // error
  size_t bytesize = sizeof(uint16_t) * vec.size();
  ofs.write((char *)vec.data(), bytesize);
  return true;
}


uint16_t RawVector::at(size_t idx)
{
  return imgvec_.at(idx);
}


uint16_t RawVector::at(size_t row, size_t col)
{
  return imgvec_.at(row*width+col);
}


size_t RawVector::size()
{
  return imgvec_.size();
}


bool RawVector::save()
{
  return writeVector(filename, imgvec_);
}


bool RawVector::saveas(string filename)
{
  return writeVector(filename, imgvec_);
}


// ============================================================================
// ============================================================================


#define print2(a,b) std::cout << a << " " << b << endl;
#define print4(a,b,c,d) std::cout << a << " " << b << " " << c << " " << d << endl;
#define hex(a) std::cout << std::hex << a << std::dec << " ";


int main()
{
  size_t w = 640;
  size_t h = 480;
  size_t expected_size = h * w;
  RawVector raw1("bin.raw", 480, 640, 16);
  if (raw1.size()==0) {
    cout << "Error opening file '"  << raw1.filename << "'\n";
    return 1;
  } else if (raw1.size() != expected_size) {
    cout << "Error. Filesize = " << raw1.size() << " Expected size = " << expected_size << "\n";
    return 2;
  }
  
  cout << "Image Size = " << raw1.size() << " should be " << expected_size << endl;
  
  raw1.saveas("new.raw");
  
  print2("width =",raw1.width)
  
  for (int r=0; r<raw1.height; r++) {
    for (int c=0; c<raw1.width; c++) {
      hex(raw1.at(r,c))
    }
    cout << endl << endl;
  }
  
  return 0;
}


