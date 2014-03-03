//
// Copyright (c) 2014 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <iostream>

#include <stdlib.h>
#include <tet_api.h>

#include <dali/public-api/dali-core.h>
#include <dali-toolkit/dali-toolkit.h>

#include <dali-toolkit-test-suite-utils.h>

using namespace Dali;

static void Startup();
static void Cleanup();

extern "C" {
  void (*tet_startup)() = Startup;
  void (*tet_cleanup)() = Cleanup;
}

static void UtcDaliSquareDissolveEffectUninitialized();
static void UtcDaliSquareDissolveEffectPropertyNames();
static void UtcDaliSquareDissolveEffectDefaultValues();
static void UtcDaliSquareDissolveEffectCustomValues();

enum {
  POSITIVE_TC_IDX = 0x01,
  NEGATIVE_TC_IDX,
};

// Add test functionality for all APIs in the class (Positive and Negative)
extern "C" {
  struct tet_testlist tet_testlist[] = {
    { UtcDaliSquareDissolveEffectUninitialized, NEGATIVE_TC_IDX },
    { UtcDaliSquareDissolveEffectPropertyNames, POSITIVE_TC_IDX },
    { UtcDaliSquareDissolveEffectDefaultValues, POSITIVE_TC_IDX },
    { UtcDaliSquareDissolveEffectCustomValues, POSITIVE_TC_IDX },
    { NULL, 0 }
  };
}

// Called only once before first test is run.
static void Startup()
{
}

// Called only once after last test is run
static void Cleanup()
{
}

// Create bitmap image
BitmapImage CreateBitmapImage()
{
  BitmapImage image = BitmapImage::New(4,4,Pixel::RGBA8888);

  PixelBuffer* pixbuf = image.GetBuffer();

  // Using a 4x4 image gives a better blend with the GL implementation
  // than a 3x3 image
  for(size_t i=0; i<16; i++)
  {
    pixbuf[i*4+0] = 0xFF;
    pixbuf[i*4+1] = 0xFF;
    pixbuf[i*4+2] = 0xFF;
    pixbuf[i*4+3] = 0xFF;
  }

  return image;
}

static void UtcDaliSquareDissolveEffectUninitialized()
{
  ToolkitTestApplication application;

  Toolkit::SquareDissolveEffect effect;

  try
  {
    // New() must be called to create a SquareDissolveEffect or it wont be valid.
    effect.SetStep( 2.0f );
    DALI_TEST_CHECK( false );
  }
  catch (Dali::DaliException& e)
  {
    // Tests that a negative test of an assertion succeeds
    tet_printf("Assertion %s failed at %s\n", e.mCondition.c_str(), e.mLocation.c_str());
    DALI_TEST_CHECK(!effect);
  }
}

static void UtcDaliSquareDissolveEffectPropertyNames()
{
  ToolkitTestApplication application;

  Toolkit::SquareDissolveEffect effect = Toolkit::SquareDissolveEffect::New();

  // Check the names, this names are used in the shaders code,
  // if they change the shader code has to be updated
  DALI_TEST_EQUALS( effect.GetStepPropertyName(), "uStep", TEST_LOCATION );
  DALI_TEST_EQUALS( effect.GetRowsPropertyName(), "uRows", TEST_LOCATION );
  DALI_TEST_EQUALS( effect.GetColumnsPropertyName(), "uColumns", TEST_LOCATION );
  DALI_TEST_EQUALS( effect.GetTexSizePropertyName(), "texSize", TEST_LOCATION );
}

static void UtcDaliSquareDissolveEffectDefaultValues()
{
  ToolkitTestApplication application;

  Toolkit::SquareDissolveEffect effect = Toolkit::SquareDissolveEffect::New();
  DALI_TEST_CHECK( effect );

  BitmapImage image = CreateBitmapImage();

  ImageActor actor = ImageActor::New( image );
  actor.SetSize( 100.0f, 100.0f );
  actor.SetShaderEffect( effect );
  Stage::GetCurrent().Add( actor );

  application.SendNotification();
  application.Render();

  // Gets converted to opengl viewport coordinates
  DALI_TEST_CHECK(
      application.GetGlAbstraction().CheckUniformValue(
          effect.GetStepPropertyName().c_str(),
          0.1f ) );

  DALI_TEST_CHECK(
      application.GetGlAbstraction().CheckUniformValue(
          effect.GetRowsPropertyName().c_str(),
          25.0f ) );

  DALI_TEST_CHECK(
      application.GetGlAbstraction().CheckUniformValue(
          effect.GetColumnsPropertyName().c_str(),
          25.0f ) );

  DALI_TEST_CHECK(
      application.GetGlAbstraction().CheckUniformValue(
          effect.GetTexSizePropertyName().c_str(),
          Vector2(1.0f, 1.0f) ) );
}

static void UtcDaliSquareDissolveEffectCustomValues()
{
  ToolkitTestApplication application;

  Toolkit::SquareDissolveEffect effect = Toolkit::SquareDissolveEffect::New();
  DALI_TEST_CHECK( effect );

  BitmapImage image = CreateBitmapImage();

  ImageActor actor = ImageActor::New( image );
  actor.SetSize( 100.0f, 100.0f );

  effect.SetStep( 2.0f );
  effect.SetRows( 3.0f );
  effect.SetColumns( 4.0f );
  effect.SetTextureSize( Vector2(12.0f, 13.0f) );

  actor.SetShaderEffect(effect);
  Stage::GetCurrent().Add(actor);

  application.SendNotification();
  application.Render();

  // Gets converted to opengl viewport coordinates
  DALI_TEST_CHECK(
      application.GetGlAbstraction().CheckUniformValue(
          effect.GetStepPropertyName().c_str(),
          2.0f ) );

  DALI_TEST_CHECK(
      application.GetGlAbstraction().CheckUniformValue(
          effect.GetRowsPropertyName().c_str(),
          3.0f ) );

  DALI_TEST_CHECK(
      application.GetGlAbstraction().CheckUniformValue(
          effect.GetColumnsPropertyName().c_str(),
          4.0f ) );

  DALI_TEST_CHECK(
      application.GetGlAbstraction().CheckUniformValue(
          effect.GetTexSizePropertyName().c_str(),
          Vector2(12.0f, 13.0f) ) );
}
