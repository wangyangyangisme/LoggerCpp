/**
 * @file    Log.cpp
 * @brief   A RAII (private) log object constructed by the Logger class
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "Log.h"
#include "Logger.h"
#include "time.h"



Log::Log(const Logger& aLogger, Level aSeverity, bool abIsActive) :
    mLogger(aLogger),
    mSeverity(aSeverity),
    mTime(-1),
    mpStream(NULL)
{

    if (abIsActive) {
        time(&mTime);
        mpStream = new(std::ostringstream);
    }
}

Log::~Log(void)
{
    if (NULL != mpStream) {
        mLogger.output(*this);

        delete mpStream;
        mpStream = NULL;
    }

}


Log& Log::test(const char* apText)
{
    if (NULL != mpStream) {
        *mpStream << apText;
    }
    return (*this);
}
