#include "BeanFactory.h"
#include "MediaDBApp.h"
#include "MediaDBController.h"

using net::draconia::MediaDBApp;
using namespace net::draconia::mediadb;

MediaDBController::MediaDBController(const MediaDBApp &refApp)
    :   mRefApp(const_cast<MediaDBApp &>(refApp))
    ,   mObjSettingsModel(*this)
    ,   mObjStyleModel(*this)
{ }

MediaDBApp &MediaDBController::getApplication() const
{
    return(mRefApp);
}

SettingsModel &MediaDBController::getSettingsModel() const
{
    return(const_cast<MediaDBController &>(*this).mObjSettingsModel);
}

StyleModel &MediaDBController::getStyleModel() const
{
    return(const_cast<MediaDBController &>(*this).mObjStyleModel);
}
