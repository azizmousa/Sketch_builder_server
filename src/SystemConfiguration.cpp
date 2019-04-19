
#include <string>
#include "server/SystemConfiguration.h"

SystemConfiguration::SystemConfiguration(){}
SystemConfiguration::~SystemConfiguration(){}

std::string SystemConfiguration::SKETCH_BUILDER_UI_PATH;
std::string SystemConfiguration::SKETCH_BUILDER_COMPILER_PATH;
std::string SystemConfiguration::SKETCH_BUILDER_EQUALIZER_PAHT;
std::string SystemConfiguration::SKETCH_BUILDER_GENERATOR_PATH;

void SystemConfiguration::setSystemUIPath(const std::string path){
    SystemConfiguration::SKETCH_BUILDER_UI_PATH = path;
}
void SystemConfiguration::setSystemCompilerPath(const std::string path){
    SystemConfiguration::SKETCH_BUILDER_COMPILER_PATH = path;
}
void SystemConfiguration::setSystemEqualizerPath(const std::string path){
    SystemConfiguration::SKETCH_BUILDER_EQUALIZER_PAHT = path;
}
void SystemConfiguration::setSystemCodeGeneratorPath(const std::string path){
    SystemConfiguration::SKETCH_BUILDER_GENERATOR_PATH = path;
}

std::string SystemConfiguration::getSystemUIPath(){
    return SystemConfiguration::SKETCH_BUILDER_UI_PATH;
}
std::string SystemConfiguration::getSystemCompilerPath(){
    return SystemConfiguration::SKETCH_BUILDER_COMPILER_PATH;
}
std::string SystemConfiguration::getSystemEqualizerPath(){
    return SystemConfiguration::SKETCH_BUILDER_EQUALIZER_PAHT;
}
std::string SystemConfiguration::getSystemCodeGeneratorPath(){
    return SystemConfiguration::SKETCH_BUILDER_GENERATOR_PATH;
}

