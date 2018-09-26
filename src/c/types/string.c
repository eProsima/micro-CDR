
// Copyright 2017 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <microcdr/types/string.h>
#include <microcdr/types/sequence.h>

#include <string.h>

// -------------------------------------------------------------------
//              PUBLIC SERIALIZATION IMPLEMENTATIONS
// -------------------------------------------------------------------

bool mc_serialize_string(mcMicroBuffer* mb, const char* string)
{
    return mc_serialize_sequence_char(mb, string, (uint32_t)strlen(string) + 1);
}

bool mc_deserialize_string(mcMicroBuffer* mb, char* string, const uint32_t string_capacity)
{
    uint32_t length;
    return mc_deserialize_sequence_char(mb, string, string_capacity, &length);
}

bool mc_serialize_endian_string(mcMicroBuffer* mb, mrEndianness endianness, const char* string)
{
    return mc_serialize_endian_sequence_char(mb, endianness, string, (uint32_t)strlen(string) + 1);
}

bool mc_deserialize_endian_string(mcMicroBuffer* mb, mrEndianness endianness, char* string, const uint32_t string_capacity)
{
    uint32_t length;
    return mc_deserialize_endian_sequence_char(mb, endianness, string, string_capacity, &length);
}
