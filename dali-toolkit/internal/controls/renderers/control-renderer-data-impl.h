#ifndef __DALI_TOOLKIT_INTERNAL_CONTROL_RENDERER_DATA_IMPL_H__
#define __DALI_TOOLKIT_INTERNAL_CONTROL_RENDERER_DATA_IMPL_H__

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

// INTERNAL INCLUDES
#include <dali/public-api/math/vector2.h>
#include <dali/devel-api/rendering/renderer.h>

namespace Dali
{

namespace Toolkit
{

namespace Internal
{

struct Internal::ControlRenderer::Impl
{
  Geometry mGeometry;
  Shader   mShader;
  Renderer mRenderer;

  Vector2   mSize;
  Vector2   mOffset;
  Rect<int> mClipRect;
  float     mDepthIndex;
};

} // namespace Internal

} // namespace Toolkit

} // namespace Dali

#endif /* __DALI_TOOLKIT_INTERNAL_CONTROL_RENDERER_DATA_IMPL_H__ */
