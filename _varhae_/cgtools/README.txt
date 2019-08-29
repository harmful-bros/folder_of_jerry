C2000 C/C++ CODE GENERATION TOOLS
Release Notes
5.2.8
September 2010

*******************************************************************************
                             Table of Contents
*******************************************************************************

1.  Defect History
2.  Compiler Documentation Errata
3.  Development Tools Forum
4.  Defect Tracking Database
5.  New Features in 5.2.0
    4.1. Functional 32-bit CLA Assembler
    4.2. Functional 32-bit CLA Disassembler
    4.3. Linker support for CLA

==============================================================================
1. Defect History
==============================================================================

The list of defects fixed in this release as well as known issues can
be found in the file DefectHistory.txt.

==============================================================================
2. Compiler Documentation Errata
==============================================================================

Errata from the "TMS320C28x Optimizing C/C++ Compiler User's Guide" and the
"TMS320C28x Assembly Language Tools User's Guide" is available online at the
Texas Instruments Embedded Processors CG Wiki:

http://tiexpressdsp.com/wiki/index.php?title=Category:CGT

under the 'Compiler Documentation Errata' link.

This Wiki has been established to assist developers in using TI Embedded
Processor Software and Tools.  Developers are encouraged to dig through all the
articles.  Registered users can update missing or incorrect information.

==============================================================================
3. Development Tools Forum
==============================================================================

For development tools support please see the Texas Instruments
engineer-to-engineer (E2E) Community and the Development Tools
Forum at:

http://e2e.ti.com/support/development_tools/default.aspx

==============================================================================
4. Defect Tracking Database
==============================================================================

Compiler defect reports can be tracked at the Development Tools bug
database, SDOWP. The log in page for SDOWP, as well as a link to create
an account with the defect tracking database is found at:

https://cqweb.ext.ti.com/pages/SDO-Web.html

A my.ti.com account is required to access this page.  To find an issue
in SDOWP, enter your bug id in the "Find Record ID" box once logged in.
To find tables of all compiler issues click the queries under the folder:

"Public Queries" -> "Development Tools" -> "TI C-C++ Compiler"

With your SDOWP account you can save your own queries in your
"Personal Queries" folder.

==============================================================================
5. New Features in 5.2.0
==============================================================================

------------------------------------------------------------------------------
4.1. Functional 32-bit CLA Assembler
------------------------------------------------------------------------------
The 5.2.0 assembler generates code for C28x devices with the 32-bit CLA
coprocessor.  Currently, full compiler support is not available for the 
CLA. Only an assembler is available. The assembler should be invoked through 
the shell using: 

cl2000 -v28 --cla_spport=cla0

to assemble code for the CLA.  The CLA code should be in its own section, and 
the section cannot contain non-CLA instructions.

CLA instructions are pipelined, and the pipeline is unprotected. The user 
needs to insert NOPs to avoid conflicts. At this time there is no pipeline 
conflict detection mechanism in the CLA assembler.

There is no prescribed RTS to be used with the CLA. The regular small/large
model C28x libraries can be used, unless FPU32 object files are also getting
linked - in which case, the FPU32 libraries must be used. 

------------------------------------------------------------------------------
4.2. Functional 32-bit CLA Disassembler
------------------------------------------------------------------------------
Disassembler support is available for the 32-bit CLA coprocessor. The
disassembler need not be invoked with any special options. If the
object/output file contains CLA instructions, then they will appear correctly
in the disassembler output.

------------------------------------------------------------------------------
4.3. Linker support for CLA             
------------------------------------------------------------------------------
Linker support is available for the 32-bit CLA coprocessor. The linker should
work as-is without any special options. However, care must be taken in the
linker command file to put CLA input sections into one or more CLA-only output
sections. In other words, mixing of CLA and non-CLA input sections into the
same output section is illegal.

For example, it is illegal to specify the following in the linker command file:

Output_section: {
                *(cla_sect)
                *(non_cla_sect)
                } > MEM

It is also illegal to specify the same section name for a CLA and non-CLA code
section. If an assembly file containing non-CLA code has a section named
"xyz", then there should not exist any CLA code section named xyz in the same
file or in any other file that is linked into the same output file. The most 
common instance of this error happening is if CLA code is not preceded by a
".sect" directive assigning it to a specified input section. As a result, the
CLA code will be put in section ".text". If this gets compiled along with a
C/C++ source file, then the code in the C/C++ file also typically gets put
under section ".text". This will result in an error message at the link step.

Also, any data referenced by a CLA section should fit within addresses 0-64K.
The linker will give an error message if CLA sections access data outside the
0-64K address range.

Further documentation about the linker is available in SPRU513D.pdf.

