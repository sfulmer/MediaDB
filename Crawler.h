#include <string>

#pragma once

namespace net::draconia::mediadb::crawler {
    /** Preferably construct one Crawler object per source.  */
    class Crawler {
        public:
            explicit Crawler(std::string *sourceUrl);
            virtual ~Crawler() = 0;

            /** Crawl one resource at a  time, preferably using a sitemap from the settings.json file.. */
            virtual unsigned char* crawl() = 0;

        private:
            std::string sourceUrl;
    };
}