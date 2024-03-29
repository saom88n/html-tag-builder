#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>

struct Element {
  std::string name, text;
  std::vector < Element > elements;

  const size_t indent_size = 2;

  Element() {}

  Element(std::string name,
    const std::string & text): name(std::move(name)), text(text) {}

  std::string str(int indent = 0) const {
    std::ostringstream oss;
    std::string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << std::endl;
    if (text.size() > 0)
      oss << std::string(indent_size * (indent + 1), ' ') << text << std::endl;
    for (const auto & e: elements)
      oss << e.str(indent + 1);
    oss << i << "</" << name << ">" << std::endl;
    return oss.str();
  }
};
