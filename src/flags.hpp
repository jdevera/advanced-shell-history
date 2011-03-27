/*
   Copyright 2011 Carl Anderson

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef __ASH_FLAGS__
#define __ASH_FLAGS__


#define DEFINE_int(long_name, short_name, default_val, desc) \
static IntFlag FLAGS_ ## long_name(#long_name, short_name, default_val, desc)

#define DEFINE_string(long_name, short_name, default_val, desc) \
static StringFlag FLAGS_ ## long_name(#long_name, short_name, default_val, desc)

#define DEFINE_bool(long_name, short_name, default_val, desc) \
static BoolFlag FLAGS_ ## long_name(#long_name, short_name, default_val, desc)


class Flag {
  public:
    Flag(const char * long_name, const char short_name, const char * desc);
    static int parse(int * argc, char *** argv, const bool remove_flags);

  private:
    const char * long_name;
    const char short_name;
    const char * description;
};


class IntFlag : public Flag {
  public:
    IntFlag(const char * ln, const char sn, const int dv, const char * ds);

  private:
    const int default_value;
};


class StringFlag : public Flag {
  public:
    StringFlag(const char * ln, const char sn, const char * dv, const char * ds);

  private:
    const char * default_value;
};


class BoolFlag : public Flag {
  public:
    BoolFlag(const char * ln, const char an, const bool dv, const char * ds);

  private:
    const bool default_value;
};


#endif /* __ASH_FLAGS__ */
