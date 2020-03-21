#include "GeneralModel.h"

using namespace net::draconia::mediadb::model;

GeneralModel::GeneralModel()
    :   Observable()
{ }

bool GeneralModel::areEditedFieldsBold() const
{
    return(mbEditedFieldsBold);
}

bool GeneralModel::areEditedFieldsItalicized() const
{
    return(mbEditedFieldsItalicized);
}

bool GeneralModel::areLabelsBold() const
{
    return(mbLabelsBold);
}

bool GeneralModel::areLabelsItalicized() const
{
    return(mbLabelsItalicized);
}

void GeneralModel::setEditedFieldsBold(const bool bEditedFieldsBold)
{
    mbEditedFieldsBold = bEditedFieldsBold;

    setChanged();
    notifyObservers("General.EditedFieldsBold");
}

void GeneralModel::setEditedFieldsItalicized(const bool bEditedFieldsItalicized)
{
    mbEditedFieldsItalicized = bEditedFieldsItalicized;

    setChanged();
    notifyObservers("General.EditedFieldsItalicized");
}

void GeneralModel::setLabelsBold(const bool bLabelsBold)
{
    mbLabelsBold = bLabelsBold;

    setChanged();
    notifyObservers("General.LabelsBold");
}

void GeneralModel::setLabelsItalicized(const bool bLabelsItalicized)
{
    mbLabelsItalicized = bLabelsItalicized;

    setChanged();
    notifyObservers("General.LabelsItalicized");
}
