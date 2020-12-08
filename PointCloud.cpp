#include "PointCloud.h"

PointCloud::PointCloud()
{
   read(path);
}

void PointCloud::read(const string &path, const int lasVersion)

{
   ifstream inf(path, ios::binary);

   if(inf.is_open())
   {
      Header header;

      inf.read(char)&header, sizeof(header));

      assert(header.versionMaj == 1 && header.versionMin);
      assert(header.headerSize == sizeof(header));
      assert(header.pointDataRecordFormat == lasVersion);

      PointRecord3 *points = new PointRecord3[header.numberOfPoints];

      inf.seekg(header.pointDataOffset)
      for(uint32_t i = 0; i < header.numberOfPoints; i++)
      {
         inf.read((char *)&point, sizeof(PointRecord3));

         float3 v = {
            (float)(point.x * header.scaleX),
            (float)(point.y * header.scaleY),
            (float)(point.z * header.scaleZ)
         };
         cout << v.x << ", " << v.y << ", " << v.z << endl;
         verts.push_back(v);
      }

      if(!inf.good())
         throw runtime_error("Reading failed!");
   }
   else
   {
      throw runtime_error("Could not find file!");
   }
}

float3 *PointCloud::getVertsData()
{
   return verts.data();
}



