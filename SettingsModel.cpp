#include "MediaDBController.h"
#include "SettingsModel.h"

using net::draconia::mediadb::MediaDBController;
using namespace net::draconia::mediadb::model;

SettingsModel::SettingsModel(const MediaDBController &refController)
    :   mRefController(const_cast<MediaDBController &>(refController))
{ }

MediaDBController &SettingsModel::getController() const
{
    return(mRefController);
}
