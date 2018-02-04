#include "WaterReaderWriter.h"

namespace urchin
{
    Water *WaterReaderWriter::loadFrom(std::shared_ptr<XmlChunk> waterChunk, const XmlParser &xmlParser) const
    {
        auto *water = new Water();
        loadGeneralPropertiesOn(water, waterChunk, xmlParser);
        loadUnderWaterProperties(water, waterChunk, xmlParser);

        return water;
    }

    void WaterReaderWriter::writeOn(std::shared_ptr<XmlChunk> waterChunk, const Water *water, XmlWriter &xmlWriter) const
    {
        writeGeneralPropertiesOn(waterChunk, water, xmlWriter);
        writeUnderWaterPropertiesOn(waterChunk, water, xmlWriter);
    }

    void WaterReaderWriter::loadGeneralPropertiesOn(Water *water, std::shared_ptr<XmlChunk> waterChunk, const XmlParser &xmlParser) const
    {
        std::shared_ptr<XmlChunk> centerPositionChunk = xmlParser.getUniqueChunk(true, CENTER_POSITION_TAG, XmlAttribute(), waterChunk);
        water->setCenterPosition(centerPositionChunk->getPoint3Value());

        std::shared_ptr<XmlChunk> xSizeChunk = xmlParser.getUniqueChunk(true, X_SIZE_TAG, XmlAttribute(), waterChunk);
        water->setXSize(xSizeChunk->getFloatValue());

        std::shared_ptr<XmlChunk> zSizeChunk = xmlParser.getUniqueChunk(true, Z_SIZE_TAG, XmlAttribute(), waterChunk);
        water->setZSize(zSizeChunk->getFloatValue());

        std::shared_ptr<XmlChunk> waterColorChunk = xmlParser.getUniqueChunk(true, WATER_COLOR_TAG, XmlAttribute(), waterChunk);
        water->setWaterColor(waterColorChunk->getVector3Value());

        std::shared_ptr<XmlChunk> normalFilenameChunk = xmlParser.getUniqueChunk(true, NORMAL_FILENAME_TAG, XmlAttribute(), waterChunk);
        water->setNormalTexture(normalFilenameChunk->getStringValue());

        std::shared_ptr<XmlChunk> sRepeatChunk = xmlParser.getUniqueChunk(true, S_REPEAT_TAG, XmlAttribute(), waterChunk);
        water->setSRepeat(sRepeatChunk->getFloatValue());

        std::shared_ptr<XmlChunk> tRepeatChunk = xmlParser.getUniqueChunk(true, T_REPEAT_TAG, XmlAttribute(), waterChunk);
        water->setTRepeat(tRepeatChunk->getFloatValue());
    }

    void WaterReaderWriter::writeGeneralPropertiesOn(std::shared_ptr<XmlChunk> waterChunk, const Water *water, XmlWriter &xmlWriter) const
    {
        std::shared_ptr<XmlChunk> centerPositionChunk = xmlWriter.createChunk(CENTER_POSITION_TAG, XmlAttribute(), waterChunk);
        centerPositionChunk->setPoint3Value(water->getCenterPosition());

        std::shared_ptr<XmlChunk> xSizeChunk = xmlWriter.createChunk(X_SIZE_TAG, XmlAttribute(), waterChunk);
        xSizeChunk->setFloatValue(water->getXSize());

        std::shared_ptr<XmlChunk> zSizeChunk = xmlWriter.createChunk(Z_SIZE_TAG, XmlAttribute(), waterChunk);
        zSizeChunk->setFloatValue(water->getZSize());

        std::shared_ptr<XmlChunk> waterColorChunk = xmlWriter.createChunk(WATER_COLOR_TAG, XmlAttribute(), waterChunk);
        waterColorChunk->setVector3Value(water->getWaterColor());

        std::shared_ptr<XmlChunk> normalFilenameChunk = xmlWriter.createChunk(NORMAL_FILENAME_TAG, XmlAttribute(), waterChunk);
        normalFilenameChunk->setStringValue(water->getNormalTexture()->getName());

        std::shared_ptr<XmlChunk> sRepeatChunk = xmlWriter.createChunk(S_REPEAT_TAG, XmlAttribute(), waterChunk);
        sRepeatChunk->setFloatValue(water->getSRepeat());

        std::shared_ptr<XmlChunk> tRepeatChunk = xmlWriter.createChunk(T_REPEAT_TAG, XmlAttribute(), waterChunk);
        tRepeatChunk->setFloatValue(water->getTRepeat());
    }

    void WaterReaderWriter::loadUnderWaterProperties(Water *water, const std::shared_ptr<XmlChunk> &waterChunk, const XmlParser &xmlParser) const
    {
        std::shared_ptr<XmlChunk> densityChunk = xmlParser.getUniqueChunk(true, DENSITY_TAG, XmlAttribute(), waterChunk);
        water->setDensity(densityChunk->getFloatValue());

        std::shared_ptr<XmlChunk> gradientChunk = xmlParser.getUniqueChunk(true, GRADIENT_TAG, XmlAttribute(), waterChunk);
        water->setGradient(gradientChunk->getFloatValue());
    }

    void WaterReaderWriter::writeUnderWaterPropertiesOn(const std::shared_ptr<XmlChunk> &waterChunk, const Water *water, XmlWriter &xmlWriter) const
    {
        std::shared_ptr<XmlChunk> densityChunk = xmlWriter.createChunk(DENSITY_TAG, XmlAttribute(), waterChunk);
        densityChunk->setFloatValue(water->getDensity());

        std::shared_ptr<XmlChunk> gradientChunk = xmlWriter.createChunk(GRADIENT_TAG, XmlAttribute(), waterChunk);
        gradientChunk->setFloatValue(water->getGradient());
    }

}
