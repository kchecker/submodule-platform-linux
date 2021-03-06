//////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2018 Corona Labs Inc.
// Contact: support@coronalabs.com
//
// This file is part of the Corona game engine.
//
// Commercial License Usage
// Licensees holding valid commercial Corona licenses may use this file in
// accordance with the commercial license agreement between you and 
// Corona Labs Inc. For licensing terms and conditions please contact
// support@coronalabs.com or visit https://coronalabs.com/com-license
//
// GNU General Public License Usage
// Alternatively, this file may be used under the terms of the GNU General
// Public license version 3. The license is as published by the Free Software
// Foundation and appearing in the file LICENSE.GPL3 included in the packaging
// of this file. Please review the following information to ensure the GNU 
// General Public License requirements will
// be met: https://www.gnu.org/licenses/gpl-3.0.html
//
// For overview and more information on licensing please refer to README.md
//
//////////////////////////////////////////////////////////////////////////////

#include "Core/Rtt_Build.h"
#include "Rtt_LinuxScreenSurface.h"

// ----------------------------------------------------------------------------

namespace Rtt
{

#pragma region LinuxScreenSurface Class

#pragma region Constructors/Destructors
LinuxScreenSurface::LinuxScreenSurface()
	: fContext(NULL)
{
}

LinuxScreenSurface::~LinuxScreenSurface()
{
}

#pragma endregion


#pragma region Public Member Functions
void LinuxScreenSurface::SetCurrent() const
{
}

void LinuxScreenSurface::Flush() const
{
	fContext->flush();
}

S32 LinuxScreenSurface::Width() const
{
	return fContext->getWidth();
}

S32 LinuxScreenSurface::Height() const
{
	return fContext->getHeight();
}

S32 LinuxScreenSurface::DeviceWidth() const
{
	return (fContext->getOrientation() == DeviceOrientation::kUpright  || fContext->getOrientation() == DeviceOrientation::kUpsideDown) ? Width() : Height();
}

S32 LinuxScreenSurface::DeviceHeight() const
{
	return (fContext->getOrientation() == DeviceOrientation::kUpright  || fContext->getOrientation() == DeviceOrientation::kUpsideDown) ? Height() : Width();
}

void LinuxScreenSurface::getWindowSize(int* w, int* h)
{
	*w = Width();
	*h = Height();
}

DeviceOrientation::Type LinuxScreenSurface::GetOrientation() const
{
	return fContext->getOrientation();
}


#pragma endregion

#pragma endregion


#pragma region LinuxOffscreenSurface Class

#pragma region Constructors/Destructors
LinuxOffscreenSurface::LinuxOffscreenSurface(const PlatformSurface& parent)
:	fWidth(parent.Width()),
	fHeight(parent.Height())
{
}

LinuxOffscreenSurface::~LinuxOffscreenSurface()
{
}

#pragma endregion


#pragma region Public Member Functions
void LinuxOffscreenSurface::SetCurrent() const
{
}

void LinuxOffscreenSurface::Flush() const
{
}

S32 LinuxOffscreenSurface::Width() const
{
	return fWidth;
}

S32 LinuxOffscreenSurface::Height() const
{
	return fHeight;
}

#pragma endregion

#pragma endregion

// ----------------------------------------------------------------------------

} // namespace Rtt

// ----------------------------------------------------------------------------
