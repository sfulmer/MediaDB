#pragma once

#include "MediaDetailsTVEpisodePanel.h"
#include "MediaDetailsTVSeasonPanel.h"
#include "MediaDetailsTVSeriesPanel.h"
#include "MediaDetailsTVSpecialPanel.h"
#include <QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsTVPanel : public QWidget
                {
                    Q_OBJECT
                    MediaDetailsTVEpisodePanel *mPnlTVEpisode;
                    MediaDetailsTVSeasonPanel *mPnlTVSeason;
                    MediaDetailsTVSeriesPanel *mPnlTVSeries;
                    MediaDetailsTVSpecialPanel *mPnlTVSpecial;
                protected:
                    MediaDetailsTVEpisodePanel *getTVEpisodePanel();
                    MediaDetailsTVSeasonPanel *getTVSeasonPanel();
                    MediaDetailsTVSeriesPanel *getTVSeriesPanel();
                    MediaDetailsTVSpecialPanel *getTVSpecialPanel();
                    void initPanel();
                public:
                    explicit MediaDetailsTVPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
