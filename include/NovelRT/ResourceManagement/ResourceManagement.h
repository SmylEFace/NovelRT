// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root
// for more information.

#ifndef NOVELRT_RESOURCEMANAGEMENT_H
#define NOVELRT_RESOURCEMANAGEMENT_H

// ResourceManagement Dependencies
#include "../Utilities/Misc.h"
#include <cstdint>
#include <filesystem>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/bson/bson.hpp>
#include <jsoncons_ext/jsonpath/jsonpath.hpp>
#include <memory>
#include <uuid.h>
#include <vector>

/**
 * @brief The APIs for managing assets and other resources that reside in persisted storage.
 */
namespace NovelRT::ResourceManagement
{
    class ResourceLoader;
    struct TextureMetadata;
    enum class BinaryDataType : uint32_t;
    struct BinaryMemberMetadata;
    struct BinaryPackage;
    struct ShaderMetadata;
    struct AudioMetadata;
}

// clang-format off
#include "TextureMetadata.h"
#include "ResourceLoader.h"
#include "BinaryDataType.h"
#include "BinaryMemberMetadata.h"
#include "BinaryPackage.h"
#include "ShaderMetadata.h"
#include "AudioMetadata.h"
// clang-format on

#endif // NOVELRT_RESOURCEMANAGEMENT_H
