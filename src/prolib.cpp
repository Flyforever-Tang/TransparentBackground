#include "prolib.h"

QImage* transparent(QString oriImagePath)
{
    QImage oriImage(oriImagePath);
    oriImage = oriImage.convertToFormat(QImage::Format_RGBA8888);
    const uint oriWidth = static_cast<uint>(oriImage.width()), oriHeight = static_cast<uint>(oriImage.height());
    const uchar *oriImageData = oriImage.bits();
    const uint pixelBits = static_cast<uint>(oriImage.depth() / 8);
    if(pixelBits != 4)
    {
        return nullptr;
    }

    uchar *newImageData = new uchar[oriWidth * oriHeight * pixelBits];
    for(uint i = 0; i < oriWidth * oriHeight; ++i)
    {
        newImageData[i * 4] = oriImageData[i * 4];
        newImageData[i * 4 + 1] = oriImageData[i * 4 + 1];
        newImageData[i * 4 + 2] = oriImageData[i * 4 + 2];

        if(oriImageData[i * 4] > 230 && oriImageData[i * 4 + 1] > 230 && oriImageData[i * 4 + 2] > 230)
        {
            newImageData[i * 4 + 3] = 0;
        }
        else
        {
            newImageData[i * 4 + 3] = 255;
        }
    }

    return new QImage(newImageData, static_cast<int>(oriWidth), static_cast<int>(oriHeight), QImage::Format_RGBA8888);
}
