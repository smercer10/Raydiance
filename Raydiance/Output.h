#pragma once

#include <filesystem>
#include <fstream>

std::string get_timestamp();

std::ofstream open_output_file(const std::string& id);
