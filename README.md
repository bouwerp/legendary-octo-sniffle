# legendary-octo-sniffle

A GUI application for loading PNG images and applying all sorts of 


## how to build

1. clone vcpkg
2. set VCPKG_ROOT in `~/.zshrc` or `~/.bashrc` or `~/.bash_profile`
3. install packages (macos): `brew install wxwidgets opencv`
4. `cmake -B ./build -S . -DCMAKE_CXX_FLAGS="$(wx-config --cxxflags)"`
5. `cmake --build ./build`

For CLion, add the output of the `wx-config --cxxflags` command to the _Cmake options_ field in settings.