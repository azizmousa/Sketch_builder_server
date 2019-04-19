
#include <string>
#include "server/SystemConfiguration.h"

SystemConfiguration::SystemConfiguration(){}
SystemConfiguration::~SystemConfiguration(){}

void SystemConfiguration::setSystemUIPath(const std::string path){
    this->SKETCH_BUILDER_UI_PATH = path;
}
void SystemConfiguration::setSystemCompilerPath(const std::string path){
    this->SKETCH_BUILDER_COMPILER_PATH = path;
}
void SystemConfiguration::setSystemEqualizerPath(const std::string path){
    this->SKETCH_BUILDER_EQUALIZER_PAHT = path;
}
void SystemConfiguration::setSystemCodeGeneratorPath(const std::string path){
    this->SKETCH_BUILDER_GENERATOR_PATH = path;
}

std::string SystemConfiguration::getSystemUIPath()const{
    return this->SKETCH_BUILDER_UI_PATH;
}
std::string SystemConfiguration::getSystemCompilerPath()const{
    return this->SKETCH_BUILDER_COMPILER_PATH;
}
std::string SystemConfiguration::getSystemEqualizerPath()const{
    return this->SKETCH_BUILDER_EQUALIZER_PAHT;
}
std::string SystemConfiguration::getSystemCodeGeneratorPath()const{
    return this->SKETCH_BUILDER_GENERATOR_PATH;
}

