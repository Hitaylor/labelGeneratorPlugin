#include "gpsLabelGenerator.h"

CLASS_LOADER_REGISTER_CLASS(micros_label_gen::GpsLabelGeneratorPlugin, micros_label_gen::LabelGeneratorBase)

namespace micros_label_gen
{
    void GpsLabelGeneratorPlugin::print()
    {
        cout << "[GpsLabelGeneratorPlugin::print()] This is a derived class of LabelGeneratorBase to provide gps data (float32 x, float32 y, float32 z)." << endl;
    }

    /**
     * @brief generate gps data 
     * 
     * @param gpsData [out]storing the gps data (x,y,z)
     */
    void GpsLabelGeneratorPlugin::genLabel(void *gpsData)
    {

        if (gpsData == NULL)
        {
            throw("gpsData in GpsLabelGeneratorPlugin::genLabel(void * gpsData)");
            return; //这个是否不会执行？如果不执行，就删掉
        }

        _Float32 gps[3] = {0.00, 0.00, 0.00};
        std::default_random_engine random(time(NULL));

        std::uniform_real_distribution<float> distX(-180.0, 180.0);
        std::uniform_real_distribution<float> distY(-90.0, 90.0);
        std::uniform_real_distribution<float> distZ(0.0, 10000.0);

        while (flag)
        {

            gps[0] = distX(random);
            gps[1] = distY(random);
            gps[2] = distZ(random);
            printf("gps(longitude, latitude, hight) = (%lf,%lf,%lf)\n", gps[0], gps[1], gps[2]);
            memcpy(gpsData, (void *)gps, sizeof(gps));
           //users should control the frequent of the generator
            sleep(1);
        }
        
    }

    //implement the virtual functions of the super class LabelGeneratorBase
    void GpsLabelGeneratorPlugin::setReservedParam(void *aParam)
    {
        reservedParam = aParam;
    }

    void *GpsLabelGeneratorPlugin::getReservedParam()
    {
        return reservedParam;
    }

    void GpsLabelGeneratorPlugin::setFlag(int j)
    {
        cout << "GpsLabelGeneratorPlugin::setFlag flag=" << j << endl;
        flag = j;
    }

    int GpsLabelGeneratorPlugin::getFlag()
    {
        return flag;
    }

    //setter/getter functions for the private members of the class GpsLabelGeneratorPlugin
    _Float32 GpsLabelGeneratorPlugin::getX() const
    {
        return x;
    }

    void GpsLabelGeneratorPlugin::setX(_Float32 aX)
    {
        x = aX;
    }

    _Float32 GpsLabelGeneratorPlugin::getY() const
    {
        return y;
    }

    void GpsLabelGeneratorPlugin::setY(_Float32 aY)
    {
        y = aY;
    }

    _Float32 GpsLabelGeneratorPlugin::getZ() const
    {
        return z;
    }

    void GpsLabelGeneratorPlugin::setZ(_Float32 aZ)
    {
        z = aZ;
    }
} // namespace micros_label_gen