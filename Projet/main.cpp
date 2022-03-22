#include "fonction.hpp"



int main() {
  png::image<png::rgb_pixel> image("Circuit/input.png");
  auto options = toml::parse("Circuit/basique.toml");

  InitImage(image, options);


  return EXIT_SUCCESS;
}
