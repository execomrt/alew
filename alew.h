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

#ifndef __alew_h__
#define __alew_h__

#ifdef __APPLE__
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#define OPENAL_VERSION 0x101
//#define ALCchar ALCubyte
//#define AL_LINEAR_DISTANCE AL_INVERSE_DISTANCE
//#define AL_LINEAR_DISTANCE_CLAMPED AL_INVERSE_DISTANCE_CLAMPED
//#define AL_EXPONENT_DISTANCE AL_INVERSE_DISTANCE
//#define AL_EXPONENT_DISTANCE_CLAMPED AL_INVERSE_DISTANCE_CLAMPED
#else
#include <al.h>
#include <alc.h>
// SDK 1.1
#include <efx.h>
#include <efx-creative.h>

// X-RAM Function pointer definitions
typedef ALboolean(__cdecl* EAXSetBufferMode)(ALsizei n, ALuint* buffers, ALint value);
typedef ALenum(__cdecl* EAXGetBufferMode)(ALuint buffer, ALint* value);

#include <EFX-Util.h>
#define OPENAL_VERSION 0x101
#endif

#ifndef ALAPI
#define ALAPI extern
#endif

#ifndef ALAPIENTRY
#define ALAPIENTRY
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/* ---------------------------------- ALC_LOKI_audio_channel ---------------------------------- */
#ifndef ALC_LOKI_audio_channel
#define ALC_LOKI_audio_channel 1

#define ALC_CHAN_MAIN_LOKI                    	0x500001
#define ALC_CHAN_PCM_LOKI                     	0x500002
#define ALC_CHAN_CD_LOKI                      	0x500003
#endif

/* ---------------------------------- LOKI_buffer_data_callback ---------------------------------- */
#ifndef LOKI_buffer_data_callback
#define LOKI_buffer_data_callback 1

	typedef void (ALAPIENTRY* PFNALBUFFERDATAWITHCALLBACK_LOKIPROC)(ALuint bid, int (*callback)(ALuint sid, ALuint bid, ALvoid* data, ALenum format, ALuint samples));
	extern PFNALBUFFERDATAWITHCALLBACK_LOKIPROC alBufferDataWithCallback;

#endif

	/* ---------------------------------- LOKI_WAVE_format ---------------------------------- */
#ifndef LOKI_WAVE_format
#define LOKI_WAVE_format 1

/* format base 0x10000 */
#define AL_FORMAT_WAVE_EXT                        0x10002

/*
 * types for special loaders.  This should be deprecated in favor
 * of the special format tags.
 */

	typedef struct WaveFMT {
		ALushort encoding;
		ALushort channels;               /* 1 = mono, 2 = stereo */
		ALuint frequency;              /* One of 11025, 22050, or 44100 Hz */
		ALuint byterate;               /* Average bytes per second */
		ALushort blockalign;             /* Bytes per sample block */
		ALushort bitspersample;
	} alWaveFMT_LOKI;

#define AL_FORMAT_WAVE_EXT                        0x10002

#endif

	/* ---------------------------------- LOKI_IMA_ADPCM_format ---------------------------------- */
#ifndef LOKI_IMA_ADPCM_format
#define LOKI_IMA_ADPCM_format 1

#define AL_FORMAT_IMA_ADPCM_MONO16_EXT            0x10000
#define AL_FORMAT_IMA_ADPCM_STEREO16_EXT          0x10001

	typedef struct _MS_ADPCM_decodestate {
		ALubyte hPredictor;
		ALushort iDelta;
		ALshort iSamp1;
		ALshort iSamp2;
	} alMSADPCM_decodestate_LOKI;

	typedef struct MS_ADPCM_decoder {
		alWaveFMT_LOKI wavefmt;
		ALushort wSamplesPerBlock;
		ALushort wNumCoef;
		ALshort aCoeff[7][2];
		/* * * */
		alMSADPCM_decodestate_LOKI state[2];
	} alMSADPCM_state_LOKI;

	typedef struct IMA_ADPCM_decodestate_s {
		ALint valprev;	/* Previous output value */
		ALbyte index;		/* Index into stepsize table */
	} alIMAADPCM_decodestate_LOKI;

	typedef struct IMA_ADPCM_decoder {
		alWaveFMT_LOKI wavefmt;
		ALushort wSamplesPerBlock;
		/* * * */
		alIMAADPCM_decodestate_LOKI state[2];
	} alIMAADPCM_state_LOKI;

	typedef ALboolean(ALAPIENTRY* PFNALUTLOADIMA_ADPCMDATA_LOKIPROC)(ALuint bid, ALvoid* data, ALuint size, alIMAADPCM_state_LOKI* ias);
	extern PFNALUTLOADIMA_ADPCMDATA_LOKIPROC alutLoadIMA_ADPCMData;

#endif


	/* ---------------------------------- LOKI_play_position ---------------------------------- */
#ifndef LOKI_play_position
#define LOKI_play_position 1
#endif

/* ---------------------------------- LOKI_quadriphonic ---------------------------------- */
#ifndef LOKI_quadriphonic
#define LOKI_quadriphonic 1

#define AL_FORMAT_QUAD8_LOKI                      0x10004
#define AL_FORMAT_QUAD16_LOKI                     0x10005

#endif

/* ---------------------------------- EXT_vorbis ---------------------------------- */
#ifndef EXT_vorbis
#define EXT_vorbis 1

#define AL_FORMAT_VORBIS_EXT      			      0x10003

	extern ALboolean ALEW_EXT_vorbis;

#endif

	/* ---------------------------------- EXT_MP3 ---------------------------------- */
#ifndef EXT_vorbis
#define EXT_vorbis 1

#define AL_FORMAT_MP3_EXT	      			      0x10004

	extern ALboolean ALEW_EXT_MP3;

#endif

	/* ---------------------------------- EXT_float32 ---------------------------------- */
#ifndef EXT_float32
#define EXT_float32 1

#define AL_FORMAT_MONO_FLOAT32					  0x10010
#define AL_FORMAT_STEREO_FLOAT32				  0x10011

	extern ALboolean ALEW_EXT_float32;

#endif

	/* ---------------------------------- EXT_buffer_offset ---------------------------------- */
#ifndef EXT_buffer_offset
#define EXT_buffer_offset 1

#define AL_BUFFER_OFFSET_EXT					  0x1019

	extern ALboolean ALEW_EXT_buffer_offset;

#endif

	/* ---------------------------------- EXT_IMA4 ---------------------------------- */
#ifndef EXT_IMA4
#define EXT_IMA4
#define AL_FORMAT_MONO_IMA4						  0x1300
#define AL_FORMAT_STEREO_IMA4					  0x1301
	extern ALboolean ALEW_EXT_IMA4;
#endif

	/* ---------------------------------- EXT_vector_unit ---------------------------------- */
#ifndef EXT_vector_unit
#define EXT_vector_unit 1

#define AL_VECTOR_UNIT_EXT						  0x3100

	extern ALboolean ALEW_EXT_vector_unit;

#endif

	/* ---------------------------------- EXT_buffer_data_static -------------------------------*/
#ifndef EXT_static_buffer
#define EXT_static_buffer 1

	typedef ALvoid(AL_APIENTRY* PFALBUFFERDATASTATICPROCPTR) (const ALint bid, ALenum format, ALvoid* data, ALsizei size, ALsizei freq);
	extern PFALBUFFERDATASTATICPROCPTR alBufferDataStatic;

	extern ALboolean ALEW_EXT_static_buffer;
#endif

	/* ---------------------------------- EXT_speaker_attrs ---------------------------------- */

#ifndef EXT_speaker_attrs
#define EXT_speaker_attrs 1

#define ALC_SPEAKER_COUNT       				  0x1032  
#define ALC_SPEAKER_GAIN        				  0x1033  
#define ALC_SPEAKER_AZIMUTH     				  0x1034  
#define ALC_SPEAKER_ELEVATION   				  0x1035  

	typedef ALvoid(ALAPIENTRY* PFALCGETSPEAKERFVPROC)(ALCdevice* dev, ALuint spk, ALenum param, ALfloat* v);
	typedef ALvoid(ALAPIENTRY* PFALCSPEAKERFVPROC)(ALCdevice* dev, ALuint spk, ALfloat* v);
	typedef ALvoid(ALAPIENTRY* PFALCSPEAKERFPROC)(ALCdevice* dev, ALuint spk, ALfloat x);

	extern PFALCGETSPEAKERFVPROC alcGetSpeakerfv;
	extern PFALCSPEAKERFVPROC alcSpeakerfv;
	extern PFALCSPEAKERFPROC alcSpeakerf;

#endif


	/* ---------------------------------- EXT_capture ---------------------------------- */
#ifndef ALC_VERSION_0_1
#ifndef EXT_capture
#define EXT_capture 1

#define ALC_CAPTURE_DEVICE_SPECIFIER			 0x310
#define ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER	 0x311
#define ALC_CAPTURE_SAMPLES					     0x312

	typedef ALCdevice* (ALAPIENTRY* PFALCCAPTUREOPENDEVICEPROC)(const ALbyte* deviceName, ALuint freq, ALenum fmt, ALsizei bufsize);
	typedef ALboolean(ALAPIENTRY* PFALCCAPTURECLOSEDEVICEPROC)(ALCdevice* device);
	typedef void (ALAPIENTRY* PFALCCAPTURESTARTPROC)(ALCdevice* device);
	typedef void (ALAPIENTRY* PFALCCAPTURESTOPPROC)(ALCdevice* device);
	typedef void (ALAPIENTRY* PFALCCAPTURESAMPLESPROC)(ALCdevice* device, ALvoid* buf, ALCsizei samps);

	extern ALboolean ALEW_EXT_capture;
	extern PFALCCAPTUREOPENDEVICEPROC alcCaptureOpenDevice;
	extern PFALCCAPTURECLOSEDEVICEPROC alcCaptureCloseDevice;
	extern PFALCCAPTURESTARTPROC alcCaptureStart;
	extern PFALCCAPTURESTOPPROC alcCaptureStop;
	extern PFALCCAPTURESAMPLESPROC alcCaptureSamples;

#endif

#endif

	/* ---------------------------------- EAX2.0 ---------------------------------- */
#ifndef EAX2_0
#define EAX2_0 1

	typedef enum
	{
		DSPROPERTY_EAX2BUFFER_NONE,
		DSPROPERTY_EAX2BUFFER_ALLPARAMETERS,
		DSPROPERTY_EAX2BUFFER_DIRECT,
		DSPROPERTY_EAX2BUFFER_DIRECTHF,
		DSPROPERTY_EAX2BUFFER_ROOM,
		DSPROPERTY_EAX2BUFFER_ROOMHF,
		DSPROPERTY_EAX2BUFFER_ROOMROLLOFFFACTOR,
		DSPROPERTY_EAX2BUFFER_OBSTRUCTION,
		DSPROPERTY_EAX2BUFFER_OBSTRUCTIONLFRATIO,
		DSPROPERTY_EAX2BUFFER_OCCLUSION,
		DSPROPERTY_EAX2BUFFER_OCCLUSIONLFRATIO,
		DSPROPERTY_EAX2BUFFER_OCCLUSIONROOMRATIO,
		DSPROPERTY_EAX2BUFFER_OUTSIDEVOLUMEHF,
		DSPROPERTY_EAX2BUFFER_AIRABSORPTIONFACTOR,
		DSPROPERTY_EAX2BUFFER_FLAGS
	} DSPROPERTY_EAX2_BUFFERPROPERTY;


	typedef enum
	{
		DSPROPERTY_EAX2LISTENER_NONE,
		DSPROPERTY_EAX2LISTENER_ALLPARAMETERS,
		DSPROPERTY_EAX2LISTENER_ROOM,
		DSPROPERTY_EAX2LISTENER_ROOMHF,
		DSPROPERTY_EAX2LISTENER_ROOMROLLOFFFACTOR,
		DSPROPERTY_EAX2LISTENER_DECAYTIME,
		DSPROPERTY_EAX2LISTENER_DECAYHFRATIO,
		DSPROPERTY_EAX2LISTENER_REFLECTIONS,
		DSPROPERTY_EAX2LISTENER_REFLECTIONSDELAY,
		DSPROPERTY_EAX2LISTENER_REVERB,
		DSPROPERTY_EAX2LISTENER_REVERBDELAY,
		DSPROPERTY_EAX2LISTENER_ENVIRONMENT,
		DSPROPERTY_EAX2LISTENER_ENVIRONMENTSIZE,
		DSPROPERTY_EAX2LISTENER_ENVIRONMENTDIFFUSION,
		DSPROPERTY_EAX2LISTENER_AIRABSORPTIONHF,
		DSPROPERTY_EAX2LISTENER_FLAGS
	} DSPROPERTY_EAX2_LISTENERPROPERTY;

	struct _GUID;

	typedef ALvoid(ALAPIENTRY* PFEAXGETPROC)(const struct _GUID* propertySetID, ALuint property, ALuint source, ALvoid* value, ALuint size);
	typedef ALvoid(ALAPIENTRY* PFEAXSETPROC)(const struct _GUID* propertySetID, ALuint property, ALuint source, ALvoid* value, ALuint size);
	typedef ALboolean(ALAPIENTRY* PFCHECKEAXSUPPORTPROC)(const ALubyte* szEAXName);

	extern ALboolean ALEW_EAX2_0;
	extern PFCHECKEAXSUPPORTPROC CheckEAXSupport;
	extern PFEAXGETPROC eaxGet;
	extern PFEAXSETPROC eaxSet;

#endif

	/* ---------------------------------- EAX3.0 ---------------------------------- */
#ifndef EAX3_0
#define EAX3_0 1


	typedef enum
	{
		DSPROPERTY_EAX3LISTENER_NONE,
		DSPROPERTY_EAX3LISTENER_ALLPARAMETERS,
		DSPROPERTY_EAX3LISTENER_ENVIRONMENT,
		DSPROPERTY_EAX3LISTENER_ENVIRONMENTSIZE,
		DSPROPERTY_EAX3LISTENER_ENVIRONMENTDIFFUSION,
		DSPROPERTY_EAX3LISTENER_ROOM,
		DSPROPERTY_EAX3LISTENER_ROOMHF,
		DSPROPERTY_EAX3LISTENER_ROOMLF,
		DSPROPERTY_EAX3LISTENER_DECAYTIME,
		DSPROPERTY_EAX3LISTENER_DECAYHFRATIO,
		DSPROPERTY_EAX3LISTENER_DECAYLFRATIO,
		DSPROPERTY_EAX3LISTENER_REFLECTIONS,
		DSPROPERTY_EAX3LISTENER_REFLECTIONSDELAY,
		DSPROPERTY_EAX3LISTENER_REFLECTIONSPAN,
		DSPROPERTY_EAX3LISTENER_REVERB,
		DSPROPERTY_EAX3LISTENER_REVERBDELAY,
		DSPROPERTY_EAX3LISTENER_REVERBPAN,
		DSPROPERTY_EAX3LISTENER_ECHOTIME,
		DSPROPERTY_EAX3LISTENER_ECHODEPTH,
		DSPROPERTY_EAX3LISTENER_MODULATIONTIME,
		DSPROPERTY_EAX3LISTENER_MODULATIONDEPTH,
		DSPROPERTY_EAX3LISTENER_AIRABSORPTIONHF,
		DSPROPERTY_EAX3LISTENER_HFREFERENCE,
		DSPROPERTY_EAX3LISTENER_LFREFERENCE,
		DSPROPERTY_EAX3LISTENER_ROOMROLLOFFFACTOR,
		DSPROPERTY_EAX3LISTENER_FLAGS
	} DSPROPERTY_EAX3_LISTENERPROPERTY3;


	typedef enum
	{
		DSPROPERTY_EAX3BUFFER_NONE,
		DSPROPERTY_EAX3BUFFER_ALLPARAMETERS,
		DSPROPERTY_EAX3BUFFER_OBSTRUCTIONPARAMETERS,
		DSPROPERTY_EAX3BUFFER_OCCLUSIONPARAMETERS,
		DSPROPERTY_EAX3BUFFER_EXCLUSIONPARAMETERS,
		DSPROPERTY_EAX3BUFFER_DIRECT,
		DSPROPERTY_EAX3BUFFER_DIRECTHF,
		DSPROPERTY_EAX3BUFFER_ROOM,
		DSPROPERTY_EAX3BUFFER_ROOMHF,
		DSPROPERTY_EAX3BUFFER_OBSTRUCTION,
		DSPROPERTY_EAX3BUFFER_OBSTRUCTIONLFRATIO,
		DSPROPERTY_EAX3BUFFER_OCCLUSION,
		DSPROPERTY_EAX3BUFFER_OCCLUSIONLFRATIO,
		DSPROPERTY_EAX3BUFFER_OCCLUSIONROOMRATIO,
		DSPROPERTY_EAX3BUFFER_OCCLUSIONDIRECTRATIO,
		DSPROPERTY_EAX3BUFFER_EXCLUSION,
		DSPROPERTY_EAX3BUFFER_EXCLUSIONLFRATIO,
		DSPROPERTY_EAX3BUFFER_OUTSIDEVOLUMEHF,
		DSPROPERTY_EAX3BUFFER_DOPPLERFACTOR,
		DSPROPERTY_EAX3BUFFER_ROLLOFFFACTOR,
		DSPROPERTY_EAX3BUFFER_ROOMROLLOFFFACTOR,
		DSPROPERTY_EAX3BUFFER_AIRABSORPTIONFACTOR,
		DSPROPERTY_EAX3BUFFER_FLAGS
	} DSPROPERTY_EAX3_BUFFERPROPERTY;



	extern ALboolean ALEW_EAX3_0;

#endif

	/* ---------------------------------- EAX4.0 ---------------------------------- */
#ifndef EAX4_0
#define EAX4_0 1
	extern ALboolean ALEW_EAX4_0;
#endif

	/* ---------------------------------- EAX5.0 ---------------------------------- */
#ifndef EAX5_0
#define EAX5_0 1
	extern ALboolean ALEW_EAX5_0;
#endif

	/* ---------------------------------- ALC_ENUMERATION_EXT ---------------------------------- */
#ifndef ALC_ENUMERATE_ALL_EXT
#define ALC_ENUMERATE_ALL_EXT 1
	extern ALboolean ALEW_ALC_ENUMERATE_ALL_EXT;
#endif

#ifndef ALC_ENUMERATION_EXT
#define ALC_ENUMERATION_EXT 1
	extern ALboolean ALEW_ALC_ENUMERATION_EXT;
#endif

	/* ---------------------------------- ALC_EXT_EFX ---------------------------------- */
#if !defined ALC_EXT_EFX && defined _WIN32
#define ALC_EXT_EFX

	extern ALboolean ALEW_ALC_EFX_EXT;

	/**
	 * Context definitions to be used with alcCreateContext.
	 * These values must be unique and not conflict with other
	 * al context values.
	 */
#define ALC_EFX_MAJOR_VERSION                              0x20001
#define ALC_EFX_MINOR_VERSION                              0x20002
#define ALC_MAX_AUXILIARY_SENDS                            0x20003




	 /**
	  * Listener definitions to be used with alListener functions.
	  * These values must be unique and not conflict with other
	  * al listener values.
	  */
#define AL_METERS_PER_UNIT                                 0x20004




	  /**
	   * Source definitions to be used with alSource functions.
	   * These values must be unique and not conflict with other
	   * al source values.
	   */
#define AL_DIRECT_FILTER                                   0x20005
#define AL_AUXILIARY_SEND_FILTER                           0x20006
#define AL_AIR_ABSORPTION_FACTOR                           0x20007
#define AL_ROOM_ROLLOFF_FACTOR                             0x20008
#define AL_CONE_OUTER_GAINHF                               0x20009
#define AL_DIRECT_FILTER_GAINHF_AUTO                       0x2000A
#define AL_AUXILIARY_SEND_FILTER_GAIN_AUTO                 0x2000B
#define AL_AUXILIARY_SEND_FILTER_GAINHF_AUTO               0x2000C




	   /**
		* Effect object definitions to be used with alEffect functions.
		*
		* Effect parameter value definitions, ranges, and defaults
		* appear farther down in this file.
		*/

		/* Reverb Parameters */
#define AL_REVERB_DENSITY                                  0x0001
#define AL_REVERB_DIFFUSION                                0x0002
#define AL_REVERB_GAIN                                     0x0003
#define AL_REVERB_GAINHF                                   0x0004
#define AL_REVERB_DECAY_TIME                               0x0005
#define AL_REVERB_DECAY_HFRATIO                            0x0006
#define AL_REVERB_REFLECTIONS_GAIN                         0x0007
#define AL_REVERB_REFLECTIONS_DELAY                        0x0008
#define AL_REVERB_LATE_REVERB_GAIN                         0x0009
#define AL_REVERB_LATE_REVERB_DELAY                        0x000A
#define AL_REVERB_AIR_ABSORPTION_GAINHF                    0x000B 
#define AL_REVERB_ROOM_ROLLOFF_FACTOR                      0x000C
#define AL_REVERB_DECAY_HFLIMIT                            0x000D

/* Chorus Parameters */
#define AL_CHORUS_WAVEFORM                                 0x0001
#define	AL_CHORUS_PHASE                                    0x0002
#define AL_CHORUS_RATE                                     0x0003
#define AL_CHORUS_DEPTH                                    0x0004
#define AL_CHORUS_FEEDBACK                                 0x0005
#define AL_CHORUS_DELAY                                    0x0006

/* Distortion Parameters */
#define AL_DISTORTION_EDGE                                 0x0001
#define AL_DISTORTION_GAIN                                 0x0002
#define AL_DISTORTION_LOWPASS_CUTOFF                       0x0003
#define AL_DISTORTION_EQCENTER                             0x0004
#define AL_DISTORTION_EQBANDWIDTH                          0x0005

/* Echo Parameters */
#define AL_ECHO_DELAY                                      0x0001
#define AL_ECHO_LRDELAY                                    0x0002
#define AL_ECHO_DAMPING                                    0x0003
#define AL_ECHO_FEEDBACK                                   0x0004
#define AL_ECHO_SPREAD                                     0x0005

/* Flanger Parameters */
#define AL_FLANGER_WAVEFORM                                0x0001
#define AL_FLANGER_PHASE                                   0x0002
#define AL_FLANGER_RATE                                    0x0003
#define AL_FLANGER_DEPTH                                   0x0004
#define AL_FLANGER_FEEDBACK                                0x0005
#define AL_FLANGER_DELAY                                   0x0006

/* Frequencyshifter Parameters */
#define AL_FREQUENCY_SHIFTER_FREQUENCY                     0x0001
#define AL_FREQUENCY_SHIFTER_LEFT_DIRECTION                0x0002
#define AL_FREQUENCY_SHIFTER_RIGHT_DIRECTION               0x0003

/* Vocalmorpher Parameters */
#define AL_VOCAL_MORPHER_PHONEMEA                          0x0001
#define AL_VOCAL_MORPHER_PHONEMEA_COARSE_TUNING            0x0002
#define AL_VOCAL_MORPHER_PHONEMEB                          0x0003
#define AL_VOCAL_MORPHER_PHONEMEB_COARSE_TUNING            0x0004
#define AL_VOCAL_MORPHER_WAVEFORM                          0x0005
#define AL_VOCAL_MORPHER_RATE                              0x0006

/* Pitchshifter Parameters */
#define AL_PITCH_SHIFTER_COARSE_TUNE                       0x0001
#define AL_PITCH_SHIFTER_FINE_TUNE                         0x0002

/* Ringmodulator Parameters */
#define AL_RING_MODULATOR_FREQUENCY                        0x0001
#define AL_RING_MODULATOR_HIGHPASS_CUTOFF                  0x0002
#define AL_RING_MODULATOR_WAVEFORM                         0x0003

/* Autowah Parameters */
#define AL_AUTOWAH_ATTACK_TIME                             0x0001
#define AL_AUTOWAH_RELEASE_TIME                            0x0002
#define AL_AUTOWAH_RESONANCE                               0x0003
#define AL_AUTOWAH_PEAK_GAIN                               0x0004

/* Compressor Parameters */
#define AL_COMPRESSOR_ONOFF                                0x0001

/* Equalizer Parameters */
#define AL_EQUALIZER_LOW_GAIN                              0x0001
#define AL_EQUALIZER_LOW_CUTOFF                            0x0002
#define AL_EQUALIZER_MID1_GAIN                             0x0003
#define AL_EQUALIZER_MID1_CENTER                           0x0004
#define AL_EQUALIZER_MID1_WIDTH                            0x0005
#define AL_EQUALIZER_MID2_GAIN                             0x0006
#define AL_EQUALIZER_MID2_CENTER                           0x0007
#define AL_EQUALIZER_MID2_WIDTH                            0x0008
#define AL_EQUALIZER_HIGH_GAIN                             0x0009
#define AL_EQUALIZER_HIGH_CUTOFF                           0x000A

/* Effect type */
#define AL_EFFECT_FIRST_PARAMETER                          0x0000
#define AL_EFFECT_LAST_PARAMETER                           0x8000
#define AL_EFFECT_TYPE                                     0x8001

/* Effect type definitions to be used with AL_EFFECT_TYPE. */
#define AL_EFFECT_NULL                                     0x0000  /* Can also be used as an Effect Object ID */
#define AL_EFFECT_REVERB                                   0x0001
#define AL_EFFECT_CHORUS                                   0x0002
#define AL_EFFECT_DISTORTION                               0x0003
#define AL_EFFECT_ECHO                                     0x0004
#define AL_EFFECT_FLANGER                                  0x0005
#define AL_EFFECT_FREQUENCY_SHIFTER                        0x0006
#define AL_EFFECT_VOCAL_MORPHER                            0x0007
#define AL_EFFECT_PITCH_SHIFTER                            0x0008
#define AL_EFFECT_RING_MODULATOR                           0x0009
#define AL_EFFECT_AUTOWAH                                  0x000A
#define AL_EFFECT_COMPRESSOR                               0x000B
#define AL_EFFECT_EQUALIZER                                0x000C

/**
 * Auxiliary Slot object definitions to be used with alAuxiliaryEffectSlot functions.
 */
#define AL_EFFECTSLOT_EFFECT                               0x0001
#define AL_EFFECTSLOT_GAIN                                 0x0002
#define AL_EFFECTSLOT_AUXILIARY_SEND_AUTO                  0x0003

 /**
  * Value to be used as an Auxiliary Slot ID to disable a source send..
  */
#define AL_EFFECTSLOT_NULL                                 0x0000



  /**
   * Filter object definitions to be used with alFilter functions.
   */

   /* Lowpass parameters. */
#define AL_LOWPASS_GAIN                                    0x0001
#define AL_LOWPASS_GAINHF                                  0x0002

/* Highpass Parameters */
#define AL_HIGHPASS_GAIN                                   0x0001
#define AL_HIGHPASS_GAINLF                                 0x0002

/* Bandpass Parameters */
#define AL_BANDPASS_GAIN                                   0x0001
#define AL_BANDPASS_GAINLF                                 0x0002
#define AL_BANDPASS_GAINHF                                 0x0003

/* Filter type */
#define AL_FILTER_FIRST_PARAMETER                          0x0000
#define AL_FILTER_LAST_PARAMETER                           0x8000
#define AL_FILTER_TYPE                                     0x8001

/* Filter type definitions to be used with AL_FILTER_TYPE. */
#define AL_FILTER_NULL                                     0x0000  /* Can also be used as a Filter Object ID */
#define	AL_FILTER_LOWPASS                                  0x0001
#define AL_FILTER_HIGHPASS                                 0x0002
#define AL_FILTER_BANDPASS                                 0x0003


/**
 * Effect object functions.
 */

 /* Create Effect objects. */
	typedef void(__cdecl* LPALGENEFFECTS)(ALsizei n, ALuint* effects);

	/* Delete Effect objects. */
	typedef void(__cdecl* LPALDELETEEFFECTS)(ALsizei n, ALuint* effects);

	/* Verify a handle is a valid Effect. */
	typedef ALboolean(__cdecl* LPALISEFFECT)(ALuint eid);

	/* Set an integer parameter for an Effect object. */
	typedef void(__cdecl* LPALEFFECTI)(ALuint eid, ALenum param, ALint value);
	typedef void(__cdecl* LPALEFFECTIV)(ALuint eid, ALenum param, ALint* values);

	/* Set a floating point parameter for an Effect object. */
	typedef void(__cdecl* LPALEFFECTF)(ALuint eid, ALenum param, ALfloat value);
	typedef void(__cdecl* LPALEFFECTFV)(ALuint eid, ALenum param, ALfloat* values);

	/* Get an integer parameter for an Effect object. */
	typedef void(__cdecl* LPALGETEFFECTI)(ALuint eid, ALenum pname, ALint* value);
	typedef void(__cdecl* LPALGETEFFECTIV)(ALuint eid, ALenum pname, ALint* values);

	/* Get a floating point parameter for an Effect object. */
	typedef void(__cdecl* LPALGETEFFECTF)(ALuint eid, ALenum pname, ALfloat* value);
	typedef void(__cdecl* LPALGETEFFECTFV)(ALuint eid, ALenum pname, ALfloat* values);


	/**
	 * Filter object functions
	 */

	 /* Create Filter objects. */
	typedef void(__cdecl* LPALGENFILTERS)(ALsizei n, ALuint* filters);

	/* Delete Filter objects. */
	typedef void(__cdecl* LPALDELETEFILTERS)(ALsizei n, ALuint* filters);

	/* Verify a handle is a valid Filter. */
	typedef ALboolean(__cdecl* LPALISFILTER)(ALuint fid);

	/* Set an integer parameter for a Filter object. */
	typedef void(__cdecl* LPALFILTERI)(ALuint fid, ALenum param, ALint value);
	typedef void(__cdecl* LPALFILTERIV)(ALuint fid, ALenum param, ALint* values);

	/* Set a floating point parameter for an Filter object. */
	typedef void(__cdecl* LPALFILTERF)(ALuint fid, ALenum param, ALfloat value);
	typedef void(__cdecl* LPALFILTERFV)(ALuint fid, ALenum param, ALfloat* values);

	/* Get an integer parameter for a Filter object. */
	typedef void(__cdecl* LPALGETFILTERI)(ALuint fid, ALenum pname, ALint* value);
	typedef void(__cdecl* LPALGETFILTERIV)(ALuint fid, ALenum pname, ALint* values);

	/* Get a floating point parameter for a Filter object. */
	typedef void(__cdecl* LPALGETFILTERF)(ALuint fid, ALenum pname, ALfloat* value);
	typedef void(__cdecl* LPALGETFILTERFV)(ALuint fid, ALenum pname, ALfloat* values);


	/**
	 * Auxiliary Slot object functions
	 */

	 /* Create Auxiliary Slot objects. */
	typedef void(__cdecl* LPALGENAUXILIARYEFFECTSLOTS)(ALsizei n, ALuint* slots);

	/* Delete Auxiliary Slot objects. */
	typedef void(__cdecl* LPALDELETEAUXILIARYEFFECTSLOTS)(ALsizei n, ALuint* slots);

	/* Verify a handle is a valid Auxiliary Slot. */
	typedef ALboolean(__cdecl* LPALISAUXILIARYEFFECTSLOT)(ALuint slot);

	/* Set an integer parameter for a Auxiliary Slot object. */
	typedef void(__cdecl* LPALAUXILIARYEFFECTSLOTI)(ALuint asid, ALenum param, ALint value);
	typedef void(__cdecl* LPALAUXILIARYEFFECTSLOTIV)(ALuint asid, ALenum param, ALint* values);

	/* Set a floating point parameter for an Auxiliary Slot object. */
	typedef void(__cdecl* LPALAUXILIARYEFFECTSLOTF)(ALuint asid, ALenum param, ALfloat value);
	typedef void(__cdecl* LPALAUXILIARYEFFECTSLOTFV)(ALuint asid, ALenum param, ALfloat* values);

	/* Get an integer parameter for a Auxiliary Slot object. */
	typedef void(__cdecl* LPALGETAUXILIARYEFFECTSLOTI)(ALuint asid, ALenum pname, ALint* value);
	typedef void(__cdecl* LPALGETAUXILIARYEFFECTSLOTIV)(ALuint asid, ALenum pname, ALint* values);

	/* Get a floating point parameter for a Auxiliary Slot object. */
	typedef void(__cdecl* LPALGETAUXILIARYEFFECTSLOTF)(ALuint asid, ALenum pname, ALfloat* value);
	typedef void(__cdecl* LPALGETAUXILIARYEFFECTSLOTFV)(ALuint asid, ALenum pname, ALfloat* values);

	// Effect objects
	extern LPALGENEFFECTS alGenEffects;
	extern LPALDELETEEFFECTS alDeleteEffects;
	extern LPALISEFFECT alIsEffect;
	extern LPALEFFECTI alEffecti;
	extern LPALEFFECTIV alEffectiv;
	extern LPALEFFECTF alEffectf;
	extern LPALEFFECTFV alEffectfv;
	extern LPALGETEFFECTI alGetEffecti;
	extern LPALGETEFFECTIV alGetEffectiv;
	extern LPALGETEFFECTF alGetEffectf;
	extern LPALGETEFFECTFV alGetEffectfv;

	//Filter objects
	extern LPALGENFILTERS alGenFilters;
	extern LPALDELETEFILTERS alDeleteFilters;
	extern LPALISFILTER alIsFilter;
	extern LPALFILTERI alFilteri;
	extern LPALFILTERIV alFilteriv;
	extern LPALFILTERF alFilterf;
	extern LPALFILTERFV alFilterfv;
	extern LPALGETFILTERI alGetFilteri;
	extern LPALGETFILTERIV alGetFilteriv;
	extern LPALGETFILTERF alGetFilterf;
	extern LPALGETFILTERFV alGetFilterfv;

	// Auxiliary slot object
	extern LPALGENAUXILIARYEFFECTSLOTS alGenAuxiliaryEffectSlots;
	extern LPALDELETEAUXILIARYEFFECTSLOTS alDeleteAuxiliaryEffectSlots;
	extern LPALISAUXILIARYEFFECTSLOT alIsAuxiliaryEffectSlot;
	extern LPALAUXILIARYEFFECTSLOTI alAuxiliaryEffectSloti;
	extern LPALAUXILIARYEFFECTSLOTIV alAuxiliaryEffectSlotiv;
	extern LPALAUXILIARYEFFECTSLOTF alAuxiliaryEffectSlotf;
	extern LPALAUXILIARYEFFECTSLOTFV alAuxiliaryEffectSlotfv;
	extern LPALGETAUXILIARYEFFECTSLOTI alGetAuxiliaryEffectSloti;
	extern LPALGETAUXILIARYEFFECTSLOTIV alGetAuxiliaryEffectSlotiv;
	extern LPALGETAUXILIARYEFFECTSLOTF alGetAuxiliaryEffectSlotf;
	extern LPALGETAUXILIARYEFFECTSLOTFV alGetAuxiliaryEffectSlotfv;



	/**********************************************************
	 * Filter ranges and defaults.
	 */

	 /**
	  * Lowpass filter
	  */

#define LOWPASS_MIN_GAIN                                   0.0f
#define LOWPASS_MAX_GAIN                                   1.0f
#define LOWPASS_DEFAULT_GAIN                               1.0f

#define LOWPASS_MIN_GAINHF                                 0.0f
#define LOWPASS_MAX_GAINHF                                 1.0f
#define LOWPASS_DEFAULT_GAINHF                             1.0f

	  /**
	   * Highpass filter
	   */

#define HIGHPASS_MIN_GAIN                                  0.0f
#define HIGHPASS_MAX_GAIN                                  1.0f
#define HIGHPASS_DEFAULT_GAIN                              1.0f

#define HIGHPASS_MIN_GAINLF                                0.0f
#define HIGHPASS_MAX_GAINLF                                1.0f
#define HIGHPASS_DEFAULT_GAINLF                            1.0f

	   /**
		* Bandpass filter
		*/

#define BANDPASS_MIN_GAIN                                  0.0f
#define BANDPASS_MAX_GAIN                                  1.0f
#define BANDPASS_DEFAULT_GAIN                              1.0f

#define BANDPASS_MIN_GAINHF                                0.0f
#define BANDPASS_MAX_GAINHF                                1.0f
#define BANDPASS_DEFAULT_GAINHF                            1.0f

#define BANDPASS_MIN_GAINLF                                0.0f
#define BANDPASS_MAX_GAINLF                                1.0f
#define BANDPASS_DEFAULT_GAINLF                            1.0f




		/**********************************************************
		* Effect parameter structures, value definitions, ranges and defaults.
		*/

		/**
		 * AL reverb effect parameter ranges and defaults
		 */
#define AL_REVERB_MIN_DENSITY                              0.0f
#define AL_REVERB_MAX_DENSITY                              1.0f
#define AL_REVERB_DEFAULT_DENSITY                          1.0f

#define AL_REVERB_MIN_DIFFUSION                            0.0f
#define AL_REVERB_MAX_DIFFUSION                            1.0f
#define AL_REVERB_DEFAULT_DIFFUSION                        1.0f

#define AL_REVERB_MIN_GAIN                                 0.0f
#define AL_REVERB_MAX_GAIN                                 1.0f
#define AL_REVERB_DEFAULT_GAIN                             0.32f

#define AL_REVERB_MIN_GAINHF                               0.0f
#define AL_REVERB_MAX_GAINHF                               1.0f
#define AL_REVERB_DEFAULT_GAINHF                           0.89f

#define AL_REVERB_MIN_DECAY_TIME                           0.1f
#define AL_REVERB_MAX_DECAY_TIME                           20.0f
#define AL_REVERB_DEFAULT_DECAY_TIME                       1.49f

#define AL_REVERB_MIN_DECAY_HFRATIO                        0.1f
#define AL_REVERB_MAX_DECAY_HFRATIO                        2.0f
#define AL_REVERB_DEFAULT_DECAY_HFRATIO                    0.83f

#define AL_REVERB_MIN_REFLECTIONS_GAIN                     0.0f
#define AL_REVERB_MAX_REFLECTIONS_GAIN                     3.16f
#define AL_REVERB_DEFAULT_REFLECTIONS_GAIN                 0.05f

#define AL_REVERB_MIN_REFLECTIONS_DELAY                    0.0f
#define AL_REVERB_MAX_REFLECTIONS_DELAY                    0.3f
#define AL_REVERB_DEFAULT_REFLECTIONS_DELAY                0.007f

#define AL_REVERB_MIN_LATE_REVERB_GAIN                     0.0f
#define AL_REVERB_MAX_LATE_REVERB_GAIN                     10.0f
#define AL_REVERB_DEFAULT_LATE_REVERB_GAIN                 1.26f

#define AL_REVERB_MIN_LATE_REVERB_DELAY                    0.0f
#define AL_REVERB_MAX_LATE_REVERB_DELAY                    0.1f
#define AL_REVERB_DEFAULT_LATE_REVERB_DELAY                0.011f

#define AL_REVERB_MIN_AIR_ABSORPTION_GAINHF                0.892f
#define AL_REVERB_MAX_AIR_ABSORPTION_GAINHF                1.0f
#define AL_REVERB_DEFAULT_AIR_ABSORPTION_GAINHF            0.994f

#define AL_REVERB_MIN_ROOM_ROLLOFF_FACTOR                  0.0f
#define AL_REVERB_MAX_ROOM_ROLLOFF_FACTOR                  10.0f
#define AL_REVERB_DEFAULT_ROOM_ROLLOFF_FACTOR              0.0f

#define AL_REVERB_MIN_DECAY_HFLIMIT                        AL_FALSE
#define AL_REVERB_MAX_DECAY_HFLIMIT                        AL_TRUE
#define AL_REVERB_DEFAULT_DECAY_HFLIMIT                    AL_TRUE

		 /**
		  * AL chorus effect parameter ranges and defaults
		  */
#define AL_CHORUS_MIN_WAVEFORM                             0
#define AL_CHORUS_MAX_WAVEFORM                             1
#define AL_CHORUS_DEFAULT_WAVEFORM                         1

#define AL_CHORUS_WAVEFORM_SINUSOID                        0
#define AL_CHORUS_WAVEFORM_TRIANGLE                        1

#define AL_CHORUS_MIN_PHASE                                (-180)
#define AL_CHORUS_MAX_PHASE                                180
#define AL_CHORUS_DEFAULT_PHASE                            90

#define AL_CHORUS_MIN_RATE                                 0.0f
#define AL_CHORUS_MAX_RATE                                 10.0f
#define AL_CHORUS_DEFAULT_RATE                             1.1f

#define AL_CHORUS_MIN_DEPTH                                0.0f
#define AL_CHORUS_MAX_DEPTH                                1.0f
#define AL_CHORUS_DEFAULT_DEPTH                            0.1f

#define AL_CHORUS_MIN_FEEDBACK                             (-1.0f)
#define AL_CHORUS_MAX_FEEDBACK                             1.0f
#define AL_CHORUS_DEFAULT_FEEDBACK                         0.25f

#define AL_CHORUS_MIN_DELAY                                0.0f
#define AL_CHORUS_MAX_DELAY                                0.016f
#define AL_CHORUS_DEFAULT_DELAY                            0.016f

		  /**
		   * AL distortion effect parameter ranges and defaults
		   */
#define AL_DISTORTION_MIN_EDGE                             0.0f
#define AL_DISTORTION_MAX_EDGE                             1.0f
#define AL_DISTORTION_DEFAULT_EDGE                         0.2f

#define AL_DISTORTION_MIN_GAIN                             0.01f
#define AL_DISTORTION_MAX_GAIN                             1.0f
#define AL_DISTORTION_DEFAULT_GAIN                         0.05f

#define AL_DISTORTION_MIN_LOWPASS_CUTOFF                   80.0f
#define AL_DISTORTION_MAX_LOWPASS_CUTOFF                   24000.0f
#define AL_DISTORTION_DEFAULT_LOWPASS_CUTOFF               8000.0f

#define AL_DISTORTION_MIN_EQCENTER                         80.0f
#define AL_DISTORTION_MAX_EQCENTER                         24000.0f
#define AL_DISTORTION_DEFAULT_EQCENTER                     3600.0f

#define AL_DISTORTION_MIN_EQBANDWIDTH                      80.0f
#define AL_DISTORTION_MAX_EQBANDWIDTH                      24000.0f
#define AL_DISTORTION_DEFAULT_EQBANDWIDTH                  3600.0f

		   /**
			* AL echo effect parameter ranges and defaults
			*/
#define AL_ECHO_MIN_DELAY                                  0.0f
#define AL_ECHO_MAX_DELAY                                  0.207f
#define AL_ECHO_DEFAULT_DELAY                              0.1f

#define AL_ECHO_MIN_LRDELAY                                0.0f
#define AL_ECHO_MAX_LRDELAY                                0.404f
#define AL_ECHO_DEFAULT_LRDELAY                            0.1f

#define AL_ECHO_MIN_DAMPING                                0.0f
#define AL_ECHO_MAX_DAMPING                                0.99f
#define AL_ECHO_DEFAULT_DAMPING                            0.5f

#define AL_ECHO_MIN_FEEDBACK                               0.0f
#define AL_ECHO_MAX_FEEDBACK                               1.0f
#define AL_ECHO_DEFAULT_FEEDBACK                           0.5f

#define AL_ECHO_MIN_SPREAD                                 (-1.0f)
#define AL_ECHO_MAX_SPREAD                                 1.0f
#define AL_ECHO_DEFAULT_SPREAD                             (-1.0f)

			/**
			 * AL flanger effect parameter ranges and defaults
			 */
#define AL_FLANGER_MIN_WAVEFORM                            0
#define AL_FLANGER_MAX_WAVEFORM                            1
#define AL_FLANGER_DEFAULT_WAVEFORM                        1

#define AL_FLANGER_WAVEFORM_SINUSOID                       0
#define AL_FLANGER_WAVEFORM_TRIANGLE                       1

#define AL_FLANGER_MIN_PHASE                               (-180)
#define AL_FLANGER_MAX_PHASE                               180
#define AL_FLANGER_DEFAULT_PHASE                           0

#define AL_FLANGER_MIN_RATE                                0.0f
#define AL_FLANGER_MAX_RATE                                10.0f
#define AL_FLANGER_DEFAULT_RATE                            0.27f

#define AL_FLANGER_MIN_DEPTH                               0.0f
#define AL_FLANGER_MAX_DEPTH                               1.0f
#define AL_FLANGER_DEFAULT_DEPTH                           1.0f

#define AL_FLANGER_MIN_FEEDBACK                            (-1.0f)
#define AL_FLANGER_MAX_FEEDBACK                            1.0f
#define AL_FLANGER_DEFAULT_FEEDBACK                        (-0.5f)

#define AL_FLANGER_MIN_DELAY                               0.0f
#define AL_FLANGER_MAX_DELAY                               0.004f
#define AL_FLANGER_DEFAULT_DELAY                           0.002f

			 /**
			  * AL frequency shifter effect parameter ranges and defaults
			  */
#define AL_FREQUENCY_SHIFTER_MIN_FREQUENCY                 0.0f
#define AL_FREQUENCY_SHIFTER_MAX_FREQUENCY                 24000.0f
#define AL_FREQUENCY_SHIFTER_DEFAULT_FREQUENCY             0.0f

#define AL_FREQUENCY_SHIFTER_MIN_LEFT_DIRECTION            0
#define AL_FREQUENCY_SHIFTER_MAX_LEFT_DIRECTION            2
#define AL_FREQUENCY_SHIFTER_DEFAULT_LEFT_DIRECTION        0

#define AL_FREQUENCY_SHIFTER_MIN_RIGHT_DIRECTION           0
#define AL_FREQUENCY_SHIFTER_MAX_RIGHT_DIRECTION           2
#define AL_FREQUENCY_SHIFTER_DEFAULT_RIGHT_DIRECTION       0

#define AL_FREQUENCY_SHIFTER_DIRECTION_DOWN                0
#define AL_FREQUENCY_SHIFTER_DIRECTION_UP                  1
#define AL_FREQUENCY_SHIFTER_DIRECTION_OFF                 2

			  /**
			   * AL vocal morpher effect parameter ranges and defaults
			   */
#define AL_VOCAL_MORPHER_MIN_PHONEMEA                      0
#define AL_VOCAL_MORPHER_MAX_PHONEMEA                      29
#define AL_VOCAL_MORPHER_DEFAULT_PHONEMEA                  0

#define AL_VOCAL_MORPHER_MIN_PHONEMEA_COARSE_TUNING	       (-24)
#define AL_VOCAL_MORPHER_MAX_PHONEMEA_COARSE_TUNING	       24
#define AL_VOCAL_MORPHER_DEFAULT_PHONEMEA_COARSE_TUNING    0

#define AL_VOCAL_MORPHER_MIN_PHONEMEB                      0
#define AL_VOCAL_MORPHER_MAX_PHONEMEB                      29
#define AL_VOCAL_MORPHER_DEFAULT_PHONEMEB                  10

#define AL_VOCAL_MORPHER_PHONEME_A                         0
#define AL_VOCAL_MORPHER_PHONEME_E                         1
#define AL_VOCAL_MORPHER_PHONEME_I                         2
#define AL_VOCAL_MORPHER_PHONEME_O                         3
#define AL_VOCAL_MORPHER_PHONEME_U                         4
#define AL_VOCAL_MORPHER_PHONEME_AA                        5
#define AL_VOCAL_MORPHER_PHONEME_AE                        6
#define AL_VOCAL_MORPHER_PHONEME_AH                        7
#define AL_VOCAL_MORPHER_PHONEME_AO                        8
#define AL_VOCAL_MORPHER_PHONEME_EH                        9
#define AL_VOCAL_MORPHER_PHONEME_ER                        10
#define AL_VOCAL_MORPHER_PHONEME_IH                        11
#define AL_VOCAL_MORPHER_PHONEME_IY                        12
#define AL_VOCAL_MORPHER_PHONEME_UH                        13
#define AL_VOCAL_MORPHER_PHONEME_UW                        14
#define AL_VOCAL_MORPHER_PHONEME_B                         15
#define AL_VOCAL_MORPHER_PHONEME_D                         16
#define AL_VOCAL_MORPHER_PHONEME_F                         17
#define AL_VOCAL_MORPHER_PHONEME_G                         18
#define AL_VOCAL_MORPHER_PHONEME_J                         19
#define AL_VOCAL_MORPHER_PHONEME_K                         20
#define AL_VOCAL_MORPHER_PHONEME_L                         21
#define AL_VOCAL_MORPHER_PHONEME_M                         22
#define AL_VOCAL_MORPHER_PHONEME_N                         23
#define AL_VOCAL_MORPHER_PHONEME_P                         24
#define AL_VOCAL_MORPHER_PHONEME_R                         25
#define AL_VOCAL_MORPHER_PHONEME_S                         26
#define AL_VOCAL_MORPHER_PHONEME_T                         27
#define AL_VOCAL_MORPHER_PHONEME_V                         28
#define AL_VOCAL_MORPHER_PHONEME_Z                         29

#define AL_VOCAL_MORPHER_MIN_PHONEMEB_COARSE_TUNING        (-24)
#define AL_VOCAL_MORPHER_MAX_PHONEMEB_COARSE_TUNING        24
#define AL_VOCAL_MORPHER_DEFAULT_PHONEMEB_COARSE_TUNING    0

#define AL_VOCAL_MORPHER_MIN_WAVEFORM                      0
#define AL_VOCAL_MORPHER_MAX_WAVEFORM                      2
#define AL_VOCAL_MORPHER_DEFAULT_WAVEFORM                  0

#define AL_VOCAL_MORPHER_WAVEFORM_SINUSOID                 0
#define AL_VOCAL_MORPHER_WAVEFORM_TRIANGLE                 1
#define AL_VOCAL_MORPHER_WAVEFORM_SAWTOOTH                 2

#define AL_VOCAL_MORPHER_MIN_RATE                          0.0f
#define AL_VOCAL_MORPHER_MAX_RATE                          10.0f
#define AL_VOCAL_MORPHER_DEFAULT_RATE                      1.41f

			   /**
				* AL pitch shifter effect parameter ranges and defaults
				*/
#define AL_PITCH_SHIFTER_MIN_COARSE_TUNE                   (-12)
#define AL_PITCH_SHIFTER_MAX_COARSE_TUNE                   12
#define AL_PITCH_SHIFTER_DEFAULT_COARSE_TUNE               12

#define AL_PITCH_SHIFTER_MIN_FINE_TUNE                     (-50)
#define AL_PITCH_SHIFTER_MAX_FINE_TUNE                     50
#define AL_PITCH_SHIFTER_DEFAULT_FINE_TUNE                 0

				/**
				 * AL ring modulator effect parameter ranges and defaults
				 */
#define AL_RING_MODULATOR_MIN_FREQUENCY                    0.0f
#define AL_RING_MODULATOR_MAX_FREQUENCY                    8000.0f
#define AL_RING_MODULATOR_DEFAULT_FREQUENCY                440.0f

#define AL_RING_MODULATOR_MIN_HIGHPASS_CUTOFF              0.0f
#define AL_RING_MODULATOR_MAX_HIGHPASS_CUTOFF              24000.0f
#define AL_RING_MODULATOR_DEFAULT_HIGHPASS_CUTOFF          800.0f

#define AL_RING_MODULATOR_MIN_WAVEFORM                     0
#define AL_RING_MODULATOR_MAX_WAVEFORM                     2
#define AL_RING_MODULATOR_DEFAULT_WAVEFORM                 0

#define AL_RING_MODULATOR_SINUSOID                         0
#define AL_RING_MODULATOR_SAWTOOTH                         1
#define AL_RING_MODULATOR_SQUARE                           2

				 /**
				  * AL autowah effect parameter ranges and defaults
				  */
#define AL_AUTOWAH_MIN_ATTACK_TIME                         0.0001f
#define AL_AUTOWAH_MAX_ATTACK_TIME                         1.0f
#define AL_AUTOWAH_DEFAULT_ATTACK_TIME                     0.06f

#define AL_AUTOWAH_MIN_RELEASE_TIME                        0.0001f
#define AL_AUTOWAH_MAX_RELEASE_TIME                        1.0f
#define AL_AUTOWAH_DEFAULT_RELEASE_TIME                    0.06f

#define AL_AUTOWAH_MIN_RESONANCE                           2.0f
#define AL_AUTOWAH_MAX_RESONANCE                           1000.0f
#define AL_AUTOWAH_DEFAULT_RESONANCE                       1000.0f

#define AL_AUTOWAH_MIN_PEAK_GAIN                           0.00003f
#define AL_AUTOWAH_MAX_PEAK_GAIN                           31621.0f
#define AL_AUTOWAH_DEFAULT_PEAK_GAIN                       11.22f

				  /**
				   * AL compressor effect parameter ranges and defaults
				   */
#define AL_COMPRESSOR_MIN_ONOFF                            0
#define AL_COMPRESSOR_MAX_ONOFF                            1
#define AL_COMPRESSOR_DEFAULT_ONOFF                        1

				   /**
					* AL equalizer effect parameter ranges and defaults
					*/
#define AL_EQUALIZER_MIN_LOW_GAIN                          0.126f
#define AL_EQUALIZER_MAX_LOW_GAIN                          7.943f
#define AL_EQUALIZER_DEFAULT_LOW_GAIN                      1.0f

#define AL_EQUALIZER_MIN_LOW_CUTOFF                        50.0f
#define AL_EQUALIZER_MAX_LOW_CUTOFF                        800.0f
#define AL_EQUALIZER_DEFAULT_LOW_CUTOFF                    200.0f

#define AL_EQUALIZER_MIN_MID1_GAIN                         0.126f
#define AL_EQUALIZER_MAX_MID1_GAIN                         7.943f
#define AL_EQUALIZER_DEFAULT_MID1_GAIN                     1.0f

#define AL_EQUALIZER_MIN_MID1_CENTER                       200.0f
#define AL_EQUALIZER_MAX_MID1_CENTER                       3000.0f
#define AL_EQUALIZER_DEFAULT_MID1_CENTER                   500.0f

#define AL_EQUALIZER_MIN_MID1_WIDTH                        0.01f
#define AL_EQUALIZER_MAX_MID1_WIDTH                        1.0f
#define AL_EQUALIZER_DEFAULT_MID1_WIDTH                    1.0f

#define AL_EQUALIZER_MIN_MID2_GAIN                         0.126f
#define AL_EQUALIZER_MAX_MID2_GAIN                         7.943f
#define AL_EQUALIZER_DEFAULT_MID2_GAIN                     1.0f

#define AL_EQUALIZER_MIN_MID2_CENTER                       1000.0f
#define AL_EQUALIZER_MAX_MID2_CENTER                       8000.0f
#define AL_EQUALIZER_DEFAULT_MID2_CENTER                   3000.0f

#define AL_EQUALIZER_MIN_MID2_WIDTH                        0.01f
#define AL_EQUALIZER_MAX_MID2_WIDTH                        1.0f
#define AL_EQUALIZER_DEFAULT_MID2_WIDTH                    1.0f

#define AL_EQUALIZER_MIN_HIGH_GAIN                         0.126f
#define AL_EQUALIZER_MAX_HIGH_GAIN                         7.943f
#define AL_EQUALIZER_DEFAULT_HIGH_GAIN                     1.0f

#define AL_EQUALIZER_MIN_HIGH_CUTOFF                       4000.0f
#define AL_EQUALIZER_MAX_HIGH_CUTOFF                       16000.0f
#define AL_EQUALIZER_DEFAULT_HIGH_CUTOFF                   6000.0f

#endif

					/// ALEW.h

					/* ---------------------------------- ALC_MAC_OSX_CONVERT_DATA_UPON_LOADING ---------------------------------- */
#ifndef ALC_MAC_OSX_CONVERT_DATA_UPON_LOADING
	extern ALboolean ALEW_MAC_OSX_convert_data_upon_loading;
	/*
	   Convert Data When Loading.
	   Default false, currently applies only to monophonic sounds. Use with alEnable()/alDisable()
	*/
#define ALC_MAC_OSX_CONVERT_DATA_UPON_LOADING           0xF001
#endif

	/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	   ALC_EXT_MAC_OSX
	  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#ifndef ALC_EXT_MAC_OSX
#define ALC_EXT_MAC_OSX 1

	extern ALboolean ALEW_EXT_MAC_OSX;

	typedef ALvoid(ALAPIENTRY* alcMacOSXRenderingQualityProcPtr) (const ALint value);
	typedef ALvoid(ALAPIENTRY* alMacOSXRenderChannelCountProcPtr) (const ALint value);
	typedef ALvoid(ALAPIENTRY* alcMacOSXMixerMaxiumumBussesProcPtr) (const ALint value);
	typedef ALvoid(ALAPIENTRY* alcMacOSXMixerOutputRateProcPtr) (const ALdouble value);

	typedef ALint(ALAPIENTRY* alcMacOSXGetRenderingQualityProcPtr) (void);
	typedef ALint(ALAPIENTRY* alMacOSXGetRenderChannelCountProcPtr) (void);
	typedef ALint(ALAPIENTRY* alcMacOSXGetMixerMaxiumumBussesProcPtr) (void);
	typedef ALdouble(ALAPIENTRY* alcMacOSXGetMixerOutputRateProcPtr) (void);

	extern alcMacOSXRenderingQualityProcPtr alcMacOSXRenderingQuality;
	extern alMacOSXRenderChannelCountProcPtr alMacOSXRenderChannelCount;
	extern alcMacOSXMixerMaxiumumBussesProcPtr alcMacOSXMixerMaxiumumBusses;
	extern alcMacOSXMixerOutputRateProcPtr alcMacOSXMixerOutputRate;

	extern alcMacOSXGetRenderingQualityProcPtr alcMacOSXGetRenderingQuality;
	extern alMacOSXGetRenderChannelCountProcPtr alMacOSXGetRenderChannelCount;
	extern alcMacOSXGetMixerMaxiumumBussesProcPtr alcMacOSXGetMixerMaxiumumBusses;
	extern alcMacOSXGetMixerOutputRateProcPtr alcMacOSXGetMixerOutputRate;

	/* Render Quality. Used with alcMacOSXRenderingQuality() */
#define ALC_MAC_OSX_SPATIAL_RENDERING_QUALITY_HIGH 'rqhi'
#define ALC_MAC_OSX_SPATIAL_RENDERING_QUALITY_LOW 'rdlo'

/*
   Render Channels. Used with alMacOSXRenderChannelCount()
   Allows a user to force OpenAL to render to stereo, regardless of the audio hardware being used
*/
#define ALC_MAC_OSX_RENDER_CHANNEL_COUNT_STEREO 'rcst'
#define ALC_MAC_OSX_RENDER_CHANNEL_COUNT_MULTICHANNEL 'rcmc'

#endif


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ALC_EXT_ASA : Apple Spatial Audio Extension
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifndef ALC_EXT_ASA
#define ALC_EXT_ASA 1

	extern ALboolean ALEW_EXT_ASA;

	typedef ALenum(ALAPIENTRY* alcASAGetSourceProcPtr) (const ALuint property, ALuint source, ALvoid* data, ALuint* dataSize);
	typedef ALenum(ALAPIENTRY* alcASASetSourceProcPtr) (const ALuint property, ALuint source, ALvoid* data, ALuint dataSize);
	typedef ALenum(ALAPIENTRY* alcASAGetListenerProcPtr) (const ALuint property, ALvoid* data, ALuint* dataSize);
	typedef ALenum(ALAPIENTRY* alcASASetListenerProcPtr) (const ALuint property, ALvoid* data, ALuint dataSize);

	extern alcASAGetSourceProcPtr alcASAGetSource;
	extern alcASASetSourceProcPtr alcASASetSource;
	extern alcASAGetListenerProcPtr alcASAGetListener;
	extern alcASASetListenerProcPtr alcASASetListener;

	/* listener properties */
#define ALC_ASA_REVERB_ON                           'rvon'  // type ALboolean
#define ALC_ASA_REVERB_GLOBAL_LEVEL                 'rvgl'  // type ALfloat -40.0 db - 40.0 db
#define ALC_ASA_REVERB_ROOM_TYPE                    'rvrt'  // type ALint

/* reverb room type presets for the ALC_ASA_REVERB_ROOM_TYPE property */
#define ALC_ASA_REVERB_ROOM_TYPE_SmallRoom          0
#define ALC_ASA_REVERB_ROOM_TYPE_MediumRoom         1
#define ALC_ASA_REVERB_ROOM_TYPE_LargeRoom          2
#define ALC_ASA_REVERB_ROOM_TYPE_MediumHall         3
#define ALC_ASA_REVERB_ROOM_TYPE_LargeHall          4
#define ALC_ASA_REVERB_ROOM_TYPE_Plate              5
#define ALC_ASA_REVERB_ROOM_TYPE_MediumChamber      6
#define ALC_ASA_REVERB_ROOM_TYPE_LargeChamber       7
#define ALC_ASA_REVERB_ROOM_TYPE_Cathedral          8
#define ALC_ASA_REVERB_ROOM_TYPE_LargeRoom2         9
#define ALC_ASA_REVERB_ROOM_TYPE_MediumHall2        10
#define ALC_ASA_REVERB_ROOM_TYPE_MediumHall3        11
#define ALC_ASA_REVERB_ROOM_TYPE_LargeHall2         12

#define ALC_ASA_REVERB_PRESET                       'rvps'  // type ALchar* - (set only) path to an au preset file

#define ALC_ASA_REVERB_EQ_GAIN                      'rveg'  // type ALfloat
#define ALC_ASA_REVERB_EQ_BANDWITH                  'rveb'  // type ALfloat
#define ALC_ASA_REVERB_EQ_FREQ                      'rvef'  // type ALfloat

#define ALC_ASA_REVERB_QUALITY                      'rvqt'  // type ALint

/* reverb quality settings for the ALC_ASA_REVERB_QUALITY property */
#define ALC_ASA_REVERB_QUALITY_Max                  0x7F
#define ALC_ASA_REVERB_QUALITY_High                 0x60
#define ALC_ASA_REVERB_QUALITY_Medium               0x40
#define ALC_ASA_REVERB_QUALITY_Low                  0x20
#define ALC_ASA_REVERB_QUALITY_Min                  0

/* source properties */
#define ALC_ASA_REVERB_SEND_LEVEL                   'rvsl'  // type ALfloat 0.0 (dry) - 1.0 (wet) (0-100% dry/wet mix, 0.0 default)
#define ALC_ASA_OCCLUSION                           'occl'  // type ALfloat -100.0 db (most occlusion) - 0.0 db (no occlusion, 0.0 default)
#define ALC_ASA_OBSTRUCTION                         'obst'  // type ALfloat -100.0 db (most obstruction) - 0.0 db (no obstruction, 0.0 default)

#endif


#ifndef AL_EXT_SOURCE_SPATIALIZATION
#define AL_EXT_SOURCE_SPATIALIZATION
	extern ALboolean ALEW_EXT_SOURCE_SPATIALIZATION;
	/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 AL_EXT_SOURCE_SPATIALIZATION
	 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
	 /*
	  Allows the rendering quality to be explicitly set on a source object, overriding the default
	  render quality set via alcMacOSXRenderingQuality(). A subsequent call to alcMacOSXRenderingQuality()
	  resets the render quality of all source objects.

	  Uses the same render settings (defined above) as alcMacOSXRenderingQuality():

	  ALC_MAC_OSX_SPATIAL_RENDERING_QUALITY_HIGH
	  ALC_MAC_OSX_SPATIAL_RENDERING_QUALITY_LOW
	  ALC_IPHONE_SPATIAL_RENDERING_QUALITY_HEADPHONES

	  Retrieve functions via alcGetProcAddress() by passing in strings: alSourceRenderingQuality or alSourceGetRenderingQuality
	  */

	typedef ALvoid(ALAPIENTRY* alSourceRenderingQualityProcPtr) (ALuint sid, ALint value);
	typedef ALint(ALAPIENTRY* alSourceGetRenderingQualityProcPtr) (ALuint sid);


#endif

	/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	ALC_EXT_ASA_ROGER_BEEP : Apple Spatial Audio Extension for Roger Beep Effect
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifndef ALC_EXT_ASA_ROGER_BEEP
#define ALC_EXT_ASA_ROGER_BEEP

	extern ALboolean ALEW_EXT_ASA_ROGER_BEEP;
	/*
	Roger Beep : an effect to simulate effects such as Walkie Talkie noise. It is designed to replace the
	source audio data with a specific 'tone' when falling below a specified db threshold for a specified time.
	This Extension will be present when the Roger Beep Audio Unit is present on the system (10.5 or greater)
	Use the alcASAGetSource() and alcASASetSource() APIs in the ALC_EXT_ASA extension.
	*/

	/* source properties */
#define ALC_ASA_ROGER_BEEP_ENABLE               'rben'  // type ALboolean   - initializes Roger Beep for use - returns error if source is not in a Stopped or Initial state
#define ALC_ASA_ROGER_BEEP_ON                   'rbon'  // type ALboolean   - set effect on/off (bypass) - default setting is true (on)
#define ALC_ASA_ROGER_BEEP_GAIN                 'rbgn'  // type ALfloat    - 20.0 (db) apply maximum effect :  -80.0(db) apply minimum effect amount
#define ALC_ASA_ROGER_BEEP_SENSITIVITY          'rbsn'  // type ALint      - specifiy a predefined sensitivity setting
#define ALC_ASA_ROGER_BEEP_TYPE                 'rbtp'  // type ALint      - choose predefined specific Roger Beep tone
#define ALC_ASA_ROGER_BEEP_PRESET               'rbps'  // type ALchar*    - path to an au preset file (set only)

/* settings for the ALC_ASA_ROGER_BEEP_TYPE property */
#define ALC_ASA_ROGER_BEEP_TYPE_quindartone         0
#define ALC_ASA_ROGER_BEEP_TYPE_whitenoise          1
#define ALC_ASA_ROGER_BEEP_TYPE_walkietalkie        2

/* settings for the ALC_ASA_ROGER_BEEP_SENSITIVITY property */

#define ALC_ASA_ROGER_BEEP_SENSITIVITY_Light        0
#define ALC_ASA_ROGER_BEEP_SENSITIVITY_Medium       1
#define ALC_ASA_ROGER_BEEP_SENSITIVITY_Heavy        2

#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ALC_EXT_ASA_DISTORTION : Apple Spatial Audio Extension for Distortion Effect
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#ifndef ALC_EXT_ASA_DISTORTION
#define ALC_EXT_ASA_DISTORTION 1

	extern ALboolean ALEW_EXT_ASA_DISTORTION;

	/*
	Distortion Effect
	This Extension will be present when the Distortion Audio Unit is present on the system (10.5 or greater)
	Use the alcASAGetSource() and alcASASetSource() APIs in the ALC_EXT_ASA extension.
	*/

	/* source properties */
#define ALC_ASA_DISTORTION_ENABLE               'dsen'  // type ALboolean   - initializes Distortion for use - returns error if source is not in a Stopped or Initial state
#define ALC_ASA_DISTORTION_ON                   'dson'  // type ALboolean   - set effect on/off (bypass) - default setting is true (on)
#define ALC_ASA_DISTORTION_MIX                  'dsmx'  // type ALfloat    - mix balance between dry signal and distortion effect - 0.0 (no effect) - 100.0 (all effect)
#define ALC_ASA_DISTORTION_TYPE                 'dstp'  // type ALint      - choose predefined distortion settings
#define ALC_ASA_DISTORTION_PRESET               'dsps'  // type ALchar*    - path to an au preset file (set only)

/* settings for the ALC_ASA_DISTORTION_TYPE property */
#define ALC_ASA_DISTORTION_TYPE_BitBrush            0
#define ALC_ASA_DISTORTION_TYPE_BufferBeats         1
#define ALC_ASA_DISTORTION_TYPE_LoFi                2
#define ALC_ASA_DISTORTION_TYPE_BrokenSpeaker       3
#define ALC_ASA_DISTORTION_TYPE_Cellphone           4
#define ALC_ASA_DISTORTION_TYPE_Decimated1          5
#define ALC_ASA_DISTORTION_TYPE_Decimated2          6
#define ALC_ASA_DISTORTION_TYPE_Decimated3          7
#define ALC_ASA_DISTORTION_TYPE_Decimated4          8
#define ALC_ASA_DISTORTION_TYPE_DistortedFunk       9
#define ALC_ASA_DISTORTION_TYPE_DistortionCubed     10
#define ALC_ASA_DISTORTION_TYPE_DistortionSquared   11
#define ALC_ASA_DISTORTION_TYPE_Echo1               12
#define ALC_ASA_DISTORTION_TYPE_Echo2               13
#define ALC_ASA_DISTORTION_TYPE_EchoTight1          14
#define ALC_ASA_DISTORTION_TYPE_EchoTight2          15
#define ALC_ASA_DISTORTION_TYPE_EverythingBroken    16
#define ALC_ASA_DISTORTION_TYPE_AlienChatter        17
#define ALC_ASA_DISTORTION_TYPE_CosmicInteference   18
#define ALC_ASA_DISTORTION_TYPE_GoldenPi            19
#define ALC_ASA_DISTORTION_TYPE_RadioTower          20
#define ALC_ASA_DISTORTION_TYPE_Waves               21

#endif


	int alewInit(void);

#ifdef __cplusplus
}
#endif
#endif // __alew_h__
