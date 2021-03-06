/*****************************************************************************
*
* ALPS Project: Algorithms and Libraries for Physics Simulations
*
* ALPS Libraries
*
* Copyright (C) 2001-2003 by Matthias Troyer <troyer@itp.phys.ethz.ch>,
*                            Synge Todo <wistaria@comp-phys.org>
*
* This software is part of the ALPS libraries, published under the ALPS
* Library License; you can use, redistribute it and/or modify it under
* the terms of the license, either version 1 or (at your option) any later
* version.
* 
* You should have received a copy of the ALPS Library License along with
* the ALPS Libraries; see the file LICENSE.txt. If not, the license is also
* available from http://alps.comp-phys.org/.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT 
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE, 
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
* DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/

/* $Id: boostdump2.C 6149 2012-05-14 05:59:33Z wistaria $ */

#include <alps/osiris.h>
#include <iostream>
#include <cstdlib>

int main()
{
#ifndef BOOST_NO_EXCEPTIONS
try {
#endif

  std::string file;
  std::cin >> file;

  alps::IXDRFileDump id=alps::IXDRFileDump(boost::filesystem::path(file));
  alps::idump_archive ar(id);
  std::cout << alps::get<bool>(ar) << ' ';
  std::cout << static_cast<int32_t>(alps::get<int8_t>(ar)) << ' ';
  std::cout << static_cast<int32_t>(alps::get<uint8_t>(ar)) << ' ';
  std::cout << alps::get<int16_t>(ar) << ' ';
  std::cout << alps::get<uint16_t>(ar) << ' ';
  std::cout << alps::get<int32_t>(ar) << ' ';
  std::cout << alps::get<uint32_t>(ar) << ' ';
  int64_t i8 = alps::get<int64_t>(ar);
  uint64_t i9(alps::get<uint64_t>(ar));
  std::cout << i8 << ' '  << i9  << ' ';
  double i10 = alps::get<double>(ar);
  std::cout << i10 << ' ';
  std::string str;
  ar >> str;
  std::cout << str << std::endl;
  
#ifndef BOOST_NO_EXCEPTIONS
}
catch (std::exception& exp) {
  std::cerr << exp.what() << std::endl;
  std::abort();
}
#endif
  return 0;
}
