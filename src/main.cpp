/*
 * Copyright (c) Tecplot, Inc.
 *
 * All rights reserved.  Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice, this list of
 *     conditions and the following disclaimer.
 *   - Redistributions in binary form must reproduce the above copyright notice, this list
 *     of conditions and the following disclaimer in the documentation and/or other
 *     materials provided with the distribution.
 *   - Neither the name of the Tecplot, Inc., nor the names of its contributors may be
 *     used to endorse or promote products derived from this software without specific
 *     prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <string>
#include "TECADDON.h"

AddOn_pa AddOnID;

EXPORTFROMADDON void STDCALL InitTecAddOn()
{
    TecUtilLockOn();

    char const* addOnName = "Example";
    char const* addOnVersion = "V1.0";
    char const* addOnAuthor = "Tecplot, Inc.";

    AddOnID = TecUtilAddOnRegister(120, addOnName, addOnVersion, addOnAuthor);

    // If add-on needs a menu, enable the code below, and create a function
    // with this signature
    // void STDCALL menuCallback(ArbParam_t clientData)
#if 0
    Menu_pa toolsMenu = TecUtilMenuGetStandard(StandardMenu_Tools);
    if (toolsMenu)
    {
        Menu_pa menuEntry = TecUtilMenuInsertOption(toolsMenu,
                                                    MENU_POSITION_LAST,
                                                    "Example Add-On...",
                                                    menuCallback,
                                                    ArbParam_t(0));
    }
#endif

    // If add-on handles macros, enable the code below, and create a function
    // with this signature
    // Boolean_t STDCALL macroCommandCallback(char* commandString, char** errorMsg) 
#if 0
    TecUtilMacroAddCommandCallback(addOnName, macroCommandCallback);
#endif

    TecUtilLockOff();
}
