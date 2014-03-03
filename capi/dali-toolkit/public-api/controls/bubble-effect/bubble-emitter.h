#ifndef __DALI_TOOLKIT_BUBBLE_EMMITER_H__
#define __DALI_TOOLKIT_BUBBLE_EMMITER_H__

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

/**
 * @addtogroup CAPI_DALI_FRAMEWORK
 * @{
 */

// INTERNAL INCLUDES
#include <dali/dali.h>
#include <dali-toolkit/public-api/controls/control.h>

namespace Dali DALI_IMPORT_API
{

namespace Toolkit
{

namespace Internal DALI_INTERNAL
{
  /**
   * BubbleEmitter implementation class
   */
  class BubbleEmitter;
}

/**
 * BubbleEmitter is used to display lots of moving bubbles on the stage.
 *
 * This is done by applying BubbleEffect to multiple specifically created meshActors.
 */
class BubbleEmitter : public Control
{
public:

  /**
   * Create an empty BubbleEmitter handle
   */
  BubbleEmitter();

  /**
   * Virtual destructor.
   */
  ~BubbleEmitter();

  /**
   * Create an initialized BubbleEmitter
   * @param[in] winSize The size of the bubble moving area, usually the same size as the background image actor.
   * @param[in] shapeImage The alpha channnel of this texture defines the bubble shape.
   * @param[in] maximumNumberOfBubble The maximum number of bubble needed.
   * @param[in] bubbleSizeRange The size range of the bubbles; x component is the low bound, and y component is the up bound.
   * @return The initialized BubbleEmitter object.
   */
  static BubbleEmitter New( const Vector2& winSize,
                            Image shapeImage,
                            unsigned int maximumNumberOfBubble,
                            const Vector2& bubbleSizeRange );


  /**
   * Copy constructor. Creates another handle that points to the same real object
   */
  BubbleEmitter( const BubbleEmitter& handle );

  /**
   * Assignment operator. Changes this handle to point to another real object
   */
  BubbleEmitter& operator=( const BubbleEmitter& rhs );

  /**
   * Downcast an Object handle to SuperBlurView.
   * If handle points to a BubbleEmitter, the downcast produces valid handle.
   * If not, the returned handle is left uninitialized.
   * @param[in] handle Handle to an object
   * @return handle to a BubbleEmitter or an uninitialized handle
   */
  static BubbleEmitter DownCast( BaseHandle handle );

  /**
   * Return the root actor of all bubbles, should then be added to stage.
   * @return The bubble root actor.
   */
  Actor GetRootActor();

  /**
   * Set Background image.
   * The bubbles pick color from this image with HSV values adjusted.
   * @param[in] bgImage The background image which provide color to bubbles.
   * @param[in] hsvDelta The hsv channel difference used to adjust the background image color.
   *            If set these vector as Vector3::Zero, original colors are used.
   */
  void SetBackground( Image bgImage, const Vector3& hsvDelta );

  /**
   * Set bubble shape.
   * The bubble mesh is a rectangular patch, but its displayed shape is decided by the alpha channel of the shape image.
   * @param[in] shapeImage The image whose alpha channel defines the bubble shape.
   */
  void SetShapeImage( Image shapeImage );

  /**
   * Set the scale factor applied to all the bubbles.
   * @param [in] scale The scale factor applied on bubbles.
   */
  void SetBubbleScale( float scale );

  /**
   * Set the density of the bubble.
   * Ideally every bubble's moving track is controlled by different uniforms in BubbleEffect shaders.
   * To increase the density, 'density' number of bubbles are sharing one group of uniforms, but with random offsets between these bubbles.
   * The available density is one to nine. The default density is five.
   * By set the density bigger than one, instead of emit one bubble each time, a 'density' number of bubbles are emitted.
   * @param[in] density The density of the bubble.
   */
  void SetBubbleDensity( unsigned int density );

  /**
   * Enable different blending mode for rendering
   * @param[in] enable If false, the default blending function for RenderableActor is used.
   */
  void SetBlendMode( bool enable );

  /**
   * Add a bubble movement to the animation.
   * @param[in] animation The animation reference.
   * By passing the animation into BubbleEmitter, the animation's duration and how many bubbles contained within this animation are freely decided in App.
   * @param[in] emitPosition The start position of the bubble movement.
   * @param[in] direction The direction used to constrain the bubble to move in an adjacent direction around it.
   * @param[in] displacement The displacement used to bound the moving distance of the bubble.
   */
  void EmitBubble( Animation& animation, const Vector2& emitPosition, const Vector2& direction, const Vector2& displacement );

  /**
   * Start an animation to enlarge every activated bubble's size and moving speed.
   * @param[in] duration The duration of the animation
   * @param[in] multiple The bubble size and moving speed will be increased gradually to multiple speed during the animation.
   */
  void StartExplosion( float duration, float multiple );

  /**
   * Reset all the parameters controlling the bubbles after animation.
   */
  void Restore();

public: // Not intended for developer use

  /**
   * Creates a handle using the Toolkit::Internal implementation.
   * @param[in]  implementation  The Control implementation.
   */
  DALI_INTERNAL BubbleEmitter(Internal::BubbleEmitter& implementation);

  /**
   * Allows the creation of this Control from an Internal::CustomActor pointer.
   * @param[in]  internal  A pointer to the internal CustomActor.
   */
  DALI_INTERNAL BubbleEmitter(Dali::Internal::CustomActor* internal);
};

} // namespace Toolkit

} // namespace Dali
/**
 * @}
 */
#endif /* __DALI_TOOLKIT_BUBBLE_EMMITER_H__ */
