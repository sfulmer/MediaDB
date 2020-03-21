#include "MediaDBController.h"
#include "StyleModel.h"

using net::draconia::mediadb::MediaDBController;
using namespace net::draconia::mediadb::model;

StyleModel::StyleModel(MediaDBController &refController)
    :   Observable()
    ,   mRefController(refController)
{ }

MediaDBController &StyleModel::getController() const
{
    return(mRefController);
}

GeneralModel &StyleModel::getGeneral() const
{
    return(const_cast<StyleModel &>(*this).mObjGeneralModel);
}

const QString &StyleModel::getWindowBackground() const
{
    return(msWindowBackground);
}

void StyleModel::setWindowBackground(const QString &sWindowBackground)
{
    msWindowBackground = sWindowBackground;

    setChanged();
    notifyObservers("WindowBackground");
}

void StyleModel::update(const Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(refObservable);

    if(sProperty.contains("General"))
        {
        setChanged();
        notifyObservers("General");
        }
}
