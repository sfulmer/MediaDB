#include "Crawler.h"

using namespace net::draconia::mediadb::crawler;

Crawler::Crawler(std::string *sourceUrl) {
    this->sourceUrl = reinterpret_cast<const char *>(sourceUrl);
}

Crawler::~Crawler() {
    this->sourceUrl = nullptr;
}

unsigned char* Crawler::crawl() {
    return reinterpret_cast<unsigned char *>(new char[0]);
}