/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef cmCTestConfigureCommand_h
#define cmCTestConfigureCommand_h

#include "cmCTestCommand.h"

/** \class cmCTestConfigure
 * \brief Run a ctest script
 *
 * cmCTestConfigureCommand defineds the command to configures the project.
 */
class cmCTestConfigureCommand : public cmCTestCommand
{
public:

  cmCTestConfigureCommand() {}

  /**
   * This is a virtual constructor for the command.
   */
  virtual cmCommand* Clone()
    {
    cmCTestConfigureCommand* ni = new cmCTestConfigureCommand;
    ni->CTest = this->CTest;
    ni->CTestScriptHandler = this->CTestScriptHandler;
    return ni;
    }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  virtual bool InitialPass(std::vector<std::string> const& args);

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  virtual const char* GetName() { return "CTEST_CONFIGURE";}

  /**
   * Succinct documentation.
   */
  virtual const char* GetTerseDocumentation()
    {
    return "Configures the repository.";
    }

  /**
   * More documentation.
   */
  virtual const char* GetFullDocumentation()
    {
    return
      "  CTEST_CONFIGURE(BUILD build_dir RETURN_VALUE res)\n"
      "Configures the given build directory and stores results in "
      "Configure.xml. The second argument is a variable that will hold "
      "return value.";
    }

  cmTypeMacro(cmCTestConfigureCommand, cmCTestCommand);

};


#endif
