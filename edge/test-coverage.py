
# Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os

Import("env")

def generateCoverageInfo(source, target, env):
    for file in os.listdir("test"):
        os.system(".pio/build/native/program test/"+file)
    os.system("lcov -d .pio/build/native/ -c -o lcov.info")
    os.system("lcov --remove lcov.info '*/tool-unity/*' '*/test/*' '*/MockArduino/*' '*/libdeps/*' '*/usr/*' -o filtered_lcov.info")
    os.system("genhtml -o cov/ --demangle-cpp filtered_lcov.info")

env.AddPostAction(".pio/build/native/program", generateCoverageInfo)