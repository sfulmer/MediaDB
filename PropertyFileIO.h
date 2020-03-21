#pragma once

#include <fstream>
#include <iostream>
#include "Properties.h"
#include <QString>

using net::draconia::util::Properties;
using namespace std;

namespace net
{
    namespace draconia
    {
        namespace io
        {
            class PropertyFileIO
            {
                fstream *mFileProperties;
                QString msFilename;
            protected:
                fstream &getPropertiesFile();
            public:
                PropertyFileIO();
                PropertyFileIO(const QString &sFilename);
                PropertyFileIO(PropertyFileIO &refToMove);
                ~PropertyFileIO();

                PropertyFileIO &operator=(PropertyFileIO &refToMoveAssign);

                QString &getFilename() const;
                Properties load();
                Properties load(const QString &sFilename);
                void save(const Properties &refProperties);
                void save(const Properties &refProperties, const QString &sFilename);
                void setFilename(const QString &sFilename);
            };
        }
    }
}
