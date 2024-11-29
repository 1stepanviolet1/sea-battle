#pragma once


#ifndef _EXPORT_DEF_H
#define _EXPORT_DEF_H


#ifdef SERIALIZATION_EXPORTS
#define SERIALIZATION_API __declspec(dllexport)

#else
#define SERIALIZATION_API __declspec(dllimport)

#endif // SERIALIZATION_EXPORTS

#define _GET_SERIALIZER_NAME(CLASS) CLASS##Serializer
#define _GET_LOADER_NAME(CLASS) CLASS##Loader


#endif // _EXPORT_DEF_H

