#include "json.h"


namespace seagame
{

Json::Json(const std::string &_filename)
    : _filename(_filename)
{
    this->__init_file();

}

Json::Json()
    : Json("settings.json")
{    }

Json::Json(const Json &other)
    : _filename(other._filename)
{
    this->__init_file();

}

Json::Json(Json &&other) noexcept
    : _file(std::move(other._file)),
      _filename(std::move(other._filename))
{    }

Json::~Json()
{
    if (this->_file.is_open())
        this->_file.close();

}

Json& 
Json::operator=(const Json &other)
{
    if (this != &other)
    {
        Json temp(other);
        *this = std::move(temp);
    }
    return *this;
}

Json& 
Json::operator=(Json &&other) noexcept
{
    if (this != &other)
    {
        Json temp(std::move(other));
        *this = std::move(temp);
    }
    return *this;
}

void 
Json::save(const nlohmann::json &_json) 
{
    this->_file.clear();
    this->_file << _json.dump(2);
    this->_file.flush();

}

nlohmann::json
Json::load(void)
{
    nlohmann::json _json;
    this->_file >> _json;
    return _json;

}


void
Json::__init_file()
{
    if (!fs::exists(this->_filename))
        std::system(
            (std::string("touch ") + this->_filename).c_str()
        );

    this->_file.open(this->_filename, std::ios::in | std::ios::out);

    if (!this->_file.is_open())
        throw std::runtime_error("Failed to open file: " + this->_filename);
        
}

} // seagame

