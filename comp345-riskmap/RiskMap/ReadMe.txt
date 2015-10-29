========================================================================
    CONSOLE APPLICATION : RiskMap Project Overview
========================================================================

This file contains a summary of what you will find in each of the files that
make up the RiskMap application.


RiskMap.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

RiskMap.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

RiskMap.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named RiskMap.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

Make sure incremental linking is off otherwise the project will not run. I still don't
understand the reason for this behaviour but it is not a necessary compilation feature even though
it is turned on by default in Visual Studio. 

There is no persistence, so every successive run of the program uses an empty map. 
Start by initializing a continent, as you will be prompted, and the menu will appear afterward.

/////////////////////////////////////////////////////////////////////////////
