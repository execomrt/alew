/*
** The OpenAL Extension Wrangler Library
** Copyright (C) 2005, S.Denis
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice,
**   this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
**   this list of conditions and the following disclaimer in the documentation
**   and/or other materials provided with the distribution.
** * The name of the author may be used to endorse or promote products
**   derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
** THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
** License Applicability. Except to the extent portions of this file are
** made subject to an alternative license as permitted in the SGI Free
** Software License B, Version 1.1 (the "License"), the contents of this
** file are subject only to the provisions of the License. You may not use
** this file except in compliance with the License. You may obtain a copy
** of the License at Silicon Graphics, Inc., attn: Legal Services, 1600
** Amphitheatre Parkway, Mountain View, CA 94043-1351, or at:
**
** http://oss.sgi.com/projects/FreeB
**
** Note that, as provided in the License, the Software is distributed on an
** "AS IS" basis, with ALL EXPRESS AND IMPLIED WARRANTIES AND CONDITIONS
** DISCLAIMED, INCLUDING, WITHOUT LIMITATION, ANY IMPLIED WARRANTIES AND
** CONDITIONS OF MERCHANTABILITY, SATISFACTORY QUALITY, FITNESS FOR A
** PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
**
*/
#include "alew.h"

#ifdef _WIN32
#pragma comment(lib, "OpenAL32.lib")
#endif

#ifdef ALC_LOKI_audio_channel
ALboolean ALEW_ALC_LOKI_audio_channel;
static ALboolean _alewInit_ALC_LOKI_audio_channel()
{
	return 1;
}
#endif

#ifdef LOKI_buffer_data_callback
ALboolean ALEW_LOKI_buffer_data_callback;
static ALboolean _alewInit_LOKI_buffer_data_callback()
{
	return 1;
}
#endif

#ifdef LOKI_IMA_ADPCM_format
ALboolean ALEW_LOKI_IMA_ADPCM_format;
static ALboolean _alewInit_LOKI_IMA_ADPCM_format()
{
	return 1;
}
#endif

#ifdef LOKI_play_position
ALboolean ALEW_LOKI_play_position;
static ALboolean _alewInit_LOKI_play_position()
{
	return 1;
}
#endif

#ifdef LOKI_quadriphonic
ALboolean ALEW_LOKI_quadriphonic;
static ALboolean _alewInit_LOKI_quadriphonic()
{
	return 1;
}
#endif

#ifdef EXT_vorbis
ALboolean ALEW_EXT_vorbis;
static ALboolean _alewInit_EXT_vorbis()
{
	return 1;
}
#endif


#ifdef EXT_static_buffer
ALboolean ALEW_EXT_static_buffer;
PFALBUFFERDATASTATICPROCPTR alBufferDataStatic;
static ALboolean _alewInit_EXT_buffer_data_static()
{
	alBufferDataStatic = (PFALBUFFERDATASTATICPROCPTR)alGetProcAddress((ALchar*)"alBufferDataStatic");
	return 1;
}
#endif

#ifdef EXT_capture
ALboolean ALEW_EXT_capture;
PFALCCAPTUREOPENDEVICEPROC alcCaptureOpenDevice;
PFALCCAPTURECLOSEDEVICEPROC alcCaptureCloseDevice;
PFALCCAPTURESTARTPROC alcCaptureStart;
PFALCCAPTURESTOPPROC alcCaptureStop;
PFALCCAPTURESAMPLESPROC alcCaptureSamples;
static ALboolean _alewInit_EXT_capture()
{
	alcCaptureOpenDevice = (PFALCCAPTUREOPENDEVICEPROC)alGetProcAddress((ALchar*)"alcCaptureOpenDevice");
	alcCaptureCloseDevice = (PFALCCAPTURECLOSEDEVICEPROC)alGetProcAddress((ALchar*)"alcCaptureCloseDevice");
	alcCaptureStart = (PFALCCAPTURESTARTPROC)alGetProcAddress((ALchar*)"alcCaptureStart");
	alcCaptureStop = (PFALCCAPTURESTOPPROC)alGetProcAddress((ALchar*)"alcCaptureStop");
	alcCaptureSamples = (PFALCCAPTURESAMPLESPROC)alGetProcAddress((ALchar*)"alcCaptureSamples");
	return 1;
}
#endif

#ifdef EAX2_0
ALboolean ALEW_EAX2_0;
PFEAXGETPROC eaxGet;
PFEAXSETPROC eaxSet;

static ALboolean _alewInit_EAX2_0()
{
	eaxGet = (PFEAXGETPROC)alGetProcAddress((ALchar*)"EAXGet");
	if (!eaxGet) return 0;
	eaxSet = (PFEAXSETPROC)alGetProcAddress((ALchar*)"EAXSet");
	if (!eaxSet) return 0;
	return 1;

}
#endif

#ifdef EAX3_0
ALboolean ALEW_EAX3_0;
static ALboolean _alewInit_EAX3_0()
{
	return 1;
}
#endif

#ifdef EAX4_0
ALboolean ALEW_EAX4_0;
static ALboolean _alewInit_EAX4_0()
{
	return 1;
}
#endif

#ifdef EAX5_0
ALboolean ALEW_EAX5_0;
static ALboolean _alewInit_EAX5_0()
{
	return 1;
}
#endif

#ifdef ALC_ENUMERATION_EXT
ALboolean ALEW_ALC_ENUMERATION_EXT;
#endif

#ifdef ALC_ENUMERATE_ALL_EXT
ALboolean ALEW_ALC_ENUMERATE_ALL_EXT;
#endif

#ifdef EXT_float32
ALboolean ALEW_EXT_float32;
static ALboolean _alewInit_EXT_float32()
{
	return 1;
}
#endif

#ifdef EXT_IMA4
ALboolean ALEW_EXT_IMA4;
static ALboolean _alewInit_EXT_IMA4()
{
	return 1;
}
#endif

#ifdef ALC_EXT_EFX
ALboolean ALEW_ALC_EFX_EXT;
// Effect objects
LPALGENEFFECTS alGenEffects;
LPALDELETEEFFECTS alDeleteEffects;
LPALISEFFECT alIsEffect;
LPALEFFECTI alEffecti;
LPALEFFECTIV alEffectiv;
LPALEFFECTF alEffectf;
LPALEFFECTFV alEffectfv;
LPALGETEFFECTI alGetEffecti;
LPALGETEFFECTIV alGetEffectiv;
LPALGETEFFECTF alGetEffectf;
LPALGETEFFECTFV alGetEffectfv;

//Filter objects
LPALGENFILTERS alGenFilters;
LPALDELETEFILTERS alDeleteFilters;
LPALISFILTER alIsFilter;
LPALFILTERI alFilteri;
LPALFILTERIV alFilteriv;
LPALFILTERF alFilterf;
LPALFILTERFV alFilterfv;
LPALGETFILTERI alGetFilteri;
LPALGETFILTERIV alGetFilteriv;
LPALGETFILTERF alGetFilterf;
LPALGETFILTERFV alGetFilterfv;

// Auxiliary slot object
LPALGENAUXILIARYEFFECTSLOTS alGenAuxiliaryEffectSlots;
LPALDELETEAUXILIARYEFFECTSLOTS alDeleteAuxiliaryEffectSlots;
LPALISAUXILIARYEFFECTSLOT alIsAuxiliaryEffectSlot;
LPALAUXILIARYEFFECTSLOTI alAuxiliaryEffectSloti;
LPALAUXILIARYEFFECTSLOTIV alAuxiliaryEffectSlotiv;
LPALAUXILIARYEFFECTSLOTF alAuxiliaryEffectSlotf;
LPALAUXILIARYEFFECTSLOTFV alAuxiliaryEffectSlotfv;
LPALGETAUXILIARYEFFECTSLOTI alGetAuxiliaryEffectSloti;
LPALGETAUXILIARYEFFECTSLOTIV alGetAuxiliaryEffectSlotiv;
LPALGETAUXILIARYEFFECTSLOTF alGetAuxiliaryEffectSlotf;
LPALGETAUXILIARYEFFECTSLOTFV alGetAuxiliaryEffectSlotfv;

static ALboolean _alewInit_EFX()
{
	alGenEffects = (LPALGENEFFECTS)alGetProcAddress("alGenEffects");
	alDeleteEffects = (LPALDELETEEFFECTS)alGetProcAddress("alDeleteEffects");
	alIsEffect = (LPALISEFFECT)alGetProcAddress("alIsEffect");
	alEffecti = (LPALEFFECTI)alGetProcAddress("alEffecti");
	alEffectiv = (LPALEFFECTIV)alGetProcAddress("alEffectiv");
	alEffectf = (LPALEFFECTF)alGetProcAddress("alEffectf");
	alEffectfv = (LPALEFFECTFV)alGetProcAddress("alEffectfv");
	alGetEffecti = (LPALGETEFFECTI)alGetProcAddress("alGetEffecti");
	alGetEffectiv = (LPALGETEFFECTIV)alGetProcAddress("alGetEffectiv");
	alGetEffectf = (LPALGETEFFECTF)alGetProcAddress("alGetEffectf");
	alGetEffectfv = (LPALGETEFFECTFV)alGetProcAddress("alGetEffectfv");
	alGenFilters = (LPALGENFILTERS)alGetProcAddress("alGenFilters");
	alDeleteFilters = (LPALDELETEFILTERS)alGetProcAddress("alDeleteFilters");
	alIsFilter = (LPALISFILTER)alGetProcAddress("alIsFilter");
	alFilteri = (LPALFILTERI)alGetProcAddress("alFilteri");
	alFilteriv = (LPALFILTERIV)alGetProcAddress("alFilteriv");
	alFilterf = (LPALFILTERF)alGetProcAddress("alFilterf");
	alFilterfv = (LPALFILTERFV)alGetProcAddress("alFilterfv");
	alGetFilteri = (LPALGETFILTERI)alGetProcAddress("alGetFilteri");
	alGetFilteriv = (LPALGETFILTERIV)alGetProcAddress("alGetFilteriv");
	alGetFilterf = (LPALGETFILTERF)alGetProcAddress("alGetFilterf");
	alGetFilterfv = (LPALGETFILTERFV)alGetProcAddress("alGetFilterfv");
	alGenAuxiliaryEffectSlots = (LPALGENAUXILIARYEFFECTSLOTS)alGetProcAddress("alGenAuxiliaryEffectSlots");
	alDeleteAuxiliaryEffectSlots = (LPALDELETEAUXILIARYEFFECTSLOTS)alGetProcAddress("alDeleteAuxiliaryEffectSlots");
	alIsAuxiliaryEffectSlot = (LPALISAUXILIARYEFFECTSLOT)alGetProcAddress("alIsAuxiliaryEffectSlot");
	alAuxiliaryEffectSloti = (LPALAUXILIARYEFFECTSLOTI)alGetProcAddress("alAuxiliaryEffectSloti");
	alAuxiliaryEffectSlotiv = (LPALAUXILIARYEFFECTSLOTIV)alGetProcAddress("alAuxiliaryEffectSlotiv");
	alAuxiliaryEffectSlotf = (LPALAUXILIARYEFFECTSLOTF)alGetProcAddress("alAuxiliaryEffectSlotf");
	alAuxiliaryEffectSlotfv = (LPALAUXILIARYEFFECTSLOTFV)alGetProcAddress("alAuxiliaryEffectSlotfv");
	alGetAuxiliaryEffectSloti = (LPALGETAUXILIARYEFFECTSLOTI)alGetProcAddress("alGetAuxiliaryEffectSloti");
	alGetAuxiliaryEffectSlotiv = (LPALGETAUXILIARYEFFECTSLOTIV)alGetProcAddress("alGetAuxiliaryEffectSlotiv");
	alGetAuxiliaryEffectSlotf = (LPALGETAUXILIARYEFFECTSLOTF)alGetProcAddress("alGetAuxiliaryEffectSlotf");
	alGetAuxiliaryEffectSlotfv = (LPALGETAUXILIARYEFFECTSLOTFV)alGetProcAddress("alGetAuxiliaryEffectSlotfv");
	return 1;
}

#endif

#ifdef ALC_MAC_OSX_CONVERT_DATA_UPON_LOADING
ALboolean ALEW_MAC_OSX_convert_data_upon_loading;
static ALboolean _alewInit_MAC_OSX_convert_data_upon_loading()
{
	return 1;
}
#endif

#ifdef ALC_EXT_MAC_OSX
ALboolean ALEW_EXT_MAC_OSX;
alcMacOSXRenderingQualityProcPtr alcMacOSXRenderingQuality;
alMacOSXRenderChannelCountProcPtr alMacOSXRenderChannelCount;
alcMacOSXMixerMaxiumumBussesProcPtr alcMacOSXMixerMaxiumumBusses;
alcMacOSXMixerOutputRateProcPtr alcMacOSXMixerOutputRate;

alcMacOSXGetRenderingQualityProcPtr alcMacOSXGetRenderingQuality;
alMacOSXGetRenderChannelCountProcPtr alMacOSXGetRenderChannelCount;
alcMacOSXGetMixerMaxiumumBussesProcPtr alcMacOSXGetMixerMaxiumumBusses;
alcMacOSXGetMixerOutputRateProcPtr alcMacOSXGetMixerOutputRate;

static ALboolean _alewInit_EXT_MAC_OSX()
{
	alcMacOSXRenderingQuality = (alcMacOSXRenderingQualityProcPtr)alGetProcAddress((ALchar*)"alcMacOSXRenderingQuality");
	alMacOSXRenderChannelCount = (alMacOSXRenderChannelCountProcPtr)alGetProcAddress((ALchar*)"alMacOSXRenderChannelCount");
	alcMacOSXMixerMaxiumumBusses = (alcMacOSXMixerMaxiumumBussesProcPtr)alGetProcAddress((ALchar*)"alcMacOSXMixerMaxiumumBusses");
	alcMacOSXMixerOutputRate = (alcMacOSXMixerOutputRateProcPtr)alGetProcAddress((ALchar*)"alcMacOSXMixerOutputRate");

	alcMacOSXGetRenderingQuality = (alcMacOSXGetRenderingQualityProcPtr)alGetProcAddress((ALchar*)"alcMacOSXGetRenderingQuality");
	alMacOSXGetRenderChannelCount = (alMacOSXGetRenderChannelCountProcPtr)alGetProcAddress((ALchar*)"alMacOSXGetRenderChannelCount");
	alcMacOSXGetMixerMaxiumumBusses = (alcMacOSXGetMixerMaxiumumBussesProcPtr)alGetProcAddress((ALchar*)"alcMacOSXGetMixerMaxiumumBusses");
	alcMacOSXGetMixerOutputRate = (alcMacOSXGetMixerOutputRateProcPtr)alGetProcAddress((ALchar*)"alcMacOSXGetMixerOutputRate");
	return 1;
}
#endif


#ifdef ALC_EXT_ASA
ALboolean ALEW_EXT_ASA;
alcASAGetSourceProcPtr alcASAGetSource;
alcASASetSourceProcPtr alcASASetSource;
alcASAGetListenerProcPtr alcASAGetListener;
alcASASetListenerProcPtr alcASASetListener;
static ALboolean _alewInit_EXT_ASA()
{
	alcASAGetSource = (alcASAGetSourceProcPtr)alGetProcAddress((ALchar*)"alcASAGetSource");
	alcASASetSource = (alcASASetSourceProcPtr)alGetProcAddress((ALchar*)"alcASASetSource");
	alcASAGetListener = (alcASAGetListenerProcPtr)alGetProcAddress((ALchar*)"alcASAGetListener");
	alcASASetListener = (alcASASetListenerProcPtr)alGetProcAddress((ALchar*)"alcASASetListener");

	return 1;
}
#endif

#ifdef AL_EXT_SOURCE_SPATIALIZATION
ALboolean ALEW_EXT_SOURCE_SPATIALIZATION;
alSourceRenderingQualityProcPtr alSourceRenderingQuality;
alSourceGetRenderingQualityProcPtr alSourceGetRenderingQuality;
static ALboolean _alewInit_EXT_SOURCE_SPATIALIZATION()
{
	alSourceRenderingQuality = (alSourceRenderingQualityProcPtr)alGetProcAddress((ALchar*)"alSourceRenderingQuality");
	alSourceGetRenderingQuality = (alSourceGetRenderingQualityProcPtr)alGetProcAddress((ALchar*)"alSourceGetRenderingQuality");


	return 1;
}
#endif



int alewInit(void)
{

#ifdef ALC_LOKI_audio_channel
	if (alIsExtensionPresent((ALchar*)"ALC_LOKI_audio_channel") == AL_TRUE)
		ALEW_ALC_LOKI_audio_channel = _alewInit_ALC_LOKI_audio_channel();
#endif

#ifdef LOKI_buffer_data_callback
	if (alIsExtensionPresent((ALchar*)"LOKI_buffer_data_callback") == AL_TRUE)
		ALEW_LOKI_buffer_data_callback = _alewInit_LOKI_buffer_data_callback();
#endif

#ifdef LOKI_IMA_ADPCM_format
	if (alIsExtensionPresent((ALchar*)"LOKI_IMA_ADPCM_format") == AL_TRUE)
		ALEW_LOKI_IMA_ADPCM_format = _alewInit_LOKI_IMA_ADPCM_format();
#endif

#ifdef LOKI_play_position
	if (alIsExtensionPresent((ALchar*)"LOKI_play_position") == AL_TRUE)
		ALEW_LOKI_play_position = _alewInit_LOKI_play_position();
#endif

#ifdef LOKI_quadriphonic
	if (alIsExtensionPresent((ALchar*)"LOKI_quadriphonic") == AL_TRUE)
		ALEW_LOKI_quadriphonic = _alewInit_LOKI_quadriphonic();
#endif

#ifdef EXT_vorbis
	if (alIsExtensionPresent((ALchar*)"EXT_vorbis") == AL_TRUE)
		ALEW_EXT_vorbis = _alewInit_EXT_vorbis();
#endif

#ifdef EXT_capture
	if (alIsExtensionPresent((ALchar*)"EXT_capture") == AL_TRUE)
		ALEW_EXT_capture = _alewInit_EXT_capture();
#endif

#ifdef EXT_static_buffer
	if (alIsExtensionPresent((ALchar*)"EXT_STATIC_BUFFER") == AL_TRUE)
		ALEW_EXT_static_buffer = _alewInit_EXT_buffer_data_static();
#endif

#ifdef EAX2_0
	if (alIsExtensionPresent((ALchar*)"EAX2.0") == AL_TRUE)
		ALEW_EAX2_0 = _alewInit_EAX2_0();
#endif

#ifdef EAX3_0
	if (alIsExtensionPresent((ALchar*)"EAX3.0") == AL_TRUE)
		ALEW_EAX3_0 = _alewInit_EAX3_0();
#endif

#ifdef EAX4_0
	if (alIsExtensionPresent((ALchar*)"EAX4.0") == AL_TRUE)
		ALEW_EAX4_0 = _alewInit_EAX4_0();
#endif

#ifdef EAX5_0
	if (alIsExtensionPresent((ALchar*)"EAX5.0") == AL_TRUE)
		ALEW_EAX5_0 = _alewInit_EAX5_0();
#endif

#ifdef EXT_float32
	if (alIsExtensionPresent((ALchar*)"EXT_float32") == AL_TRUE)
		ALEW_EXT_float32 = _alewInit_EXT_float32();
#endif

#ifdef EXT_IMA4
	if (alIsExtensionPresent((ALchar*)"EXT_IMA4") == AL_TRUE)
		ALEW_EXT_IMA4 = _alewInit_EXT_IMA4();
#endif

#ifdef ALC_ENUMERATION_EXT
	if (alcIsExtensionPresent((ALCdevice*)0, (ALchar*)"ALC_enumeration_EXT") == AL_TRUE)
		ALEW_ALC_ENUMERATION_EXT = AL_TRUE;
#endif

#ifdef ALC_ENUMERATE_ALL_EXT
	if (alcIsExtensionPresent((ALCdevice*)0, (ALchar*)"ALC_enumerate_all_EXT") == AL_TRUE)
		ALEW_ALC_ENUMERATE_ALL_EXT = AL_TRUE;
#endif

#ifdef ALC_EXT_EFX
	// Check if the extension is present
	if (alcIsExtensionPresent((ALCdevice*)0, (ALCchar*)"ALC_EXT_EFX") == AL_TRUE)
		ALEW_ALC_EFX_EXT = _alewInit_EFX();
#endif

#ifdef ALC_MAC_OSX_CONVERT_DATA_UPON_LOADING
	if (alcIsExtensionPresent((ALCdevice*)0, (ALchar*)"ALC_MAC_OSX_CONVERT_DATA_UPON_LOADING") == AL_TRUE)
		ALEW_MAC_OSX_convert_data_upon_loading = _alewInit_MAC_OSX_convert_data_upon_loading();
#endif

#ifdef ALC_EXT_MAC_OSX
	if (alcIsExtensionPresent((ALCdevice*)0, (ALchar*)"ALC_EXT_MAC_OSX") == AL_TRUE)
		ALEW_EXT_MAC_OSX = _alewInit_EXT_MAC_OSX();
#endif

#ifdef ALC_EXT_ASA
	if (alcIsExtensionPresent((ALCdevice*)0, (ALchar*)"ALC_EXT_ASA") == AL_TRUE)
		ALEW_EXT_ASA = _alewInit_EXT_ASA();
#endif

	if (alcIsExtensionPresent((ALCdevice*)0, (ALchar*)"ALC_EXT_SOURCE_SPATIALIZATION") == AL_TRUE)
		ALEW_EXT_SOURCE_SPATIALIZATION = _alewInit_EXT_SOURCE_SPATIALIZATION();
	return 0;
}
