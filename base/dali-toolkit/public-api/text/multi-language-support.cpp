/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

// FILE HEADER
#include <dali-toolkit/public-api/text/multi-language-support.h>

// INTERNAL INCLUDES
#include <dali-toolkit/internal/text/multi-language-support-impl.h>

namespace Dali
{

namespace Toolkit
{

namespace Text
{

MultilanguageSupport::MultilanguageSupport()
{
}

MultilanguageSupport::~MultilanguageSupport()
{
}

MultilanguageSupport::MultilanguageSupport( Internal::MultilanguageSupport* implementation )
: BaseHandle( implementation )
{
}

MultilanguageSupport MultilanguageSupport::Get()
{
  return Internal::MultilanguageSupport::Get();
}

void MultilanguageSupport::SetScripts( LogicalModel& model )
{
  GetImplementation( *this ).SetScripts( model );
}

void MultilanguageSupport::ValidateFonts( LogicalModel& model )
{
  GetImplementation( *this ).ValidateFonts( model );
}

} // namespace Text

} // namespace Toolkit

} // namespace Dali
