#ifndef POINTCLOUD_H
#define POINTCLOUD_H
#pragma pack (push, 1)
#include <string>


struct float3
{
    float x, y, z;

};

class PointCloud
{
    public:
        PointCloud(const std::string &path);

    private:

         #Struct needs to be tightly packed
        struct __attribute__((packed)) Header
        {
            char fileSig[4];
            uint16_t fileourceID;
            uint16_t globalEncoding;
            uint32_t guiData1;
            uint16_t guiData2;
            uint16_t guiData3;
            uint8_t guiData[8];
            uint8_t versionMaj, versionMin;
            char systemIdentifer[32];
            char genSoftware[32];
            uint16_t creationDay, creationYear;
            uint16_t headerSize;
            uint32_t pointDataOffset;
            uint32_t numVarLenRecords;
            uint8_t pointDataRecordFormat;
            uint16_t pointDataRecordLen;
            uint32_t numberOfPoints;
            uint32_t numPointsByReturn[5];
            double scaleX, scaleY, scaleZ;
            double offX, offY, offZ;
            double minX, minY, minZ;
            double maxX, maxY, maxZ;
        };

        struct __attribute__((packed)) PointRecord3
        {
            uint32_t X, Y, Z;
            uint16_t intensity;
            uint8_t flags;
            uint8_t classification;
            uint8_t scanAngleRank;
            uint8_t userData;
            uint16_t pointSourceID;
            double gpsTime;
            uint16_t red;
            uint16_t green;
            uint16_t blue;
        };


        void read(const std::string &path);
};



#endif // POINTCLOUD_H
