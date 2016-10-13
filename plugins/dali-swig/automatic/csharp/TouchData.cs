//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.9
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace Dali {

public class TouchData : BaseHandle {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  internal TouchData(global::System.IntPtr cPtr, bool cMemoryOwn) : base(NDalicPINVOKE.TouchData_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(TouchData obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~TouchData() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          NDalicPINVOKE.delete_TouchData(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

 public static TouchData GetTouchDataFromPtr(global::System.IntPtr cPtr) {
    TouchData ret = new TouchData(cPtr, false);
	if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public TouchData() : this(NDalicPINVOKE.new_TouchData__SWIG_0(), true) {
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
  }

  public TouchData(TouchData other) : this(NDalicPINVOKE.new_TouchData__SWIG_1(TouchData.getCPtr(other)), true) {
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
  }

  public TouchData Assign(TouchData other) {
    TouchData ret = new TouchData(NDalicPINVOKE.TouchData_Assign(swigCPtr, TouchData.getCPtr(other)), false);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public uint GetTime() {
    uint ret = NDalicPINVOKE.TouchData_GetTime(swigCPtr);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public uint GetPointCount() {
    uint ret = NDalicPINVOKE.TouchData_GetPointCount(swigCPtr);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int GetDeviceId(uint point) {
    int ret = NDalicPINVOKE.TouchData_GetDeviceId(swigCPtr, point);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public PointStateType GetState(uint point) {
    PointStateType ret = (PointStateType)NDalicPINVOKE.TouchData_GetState(swigCPtr, point);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public Actor GetHitActor(uint point) {
    Actor ret = new Actor(NDalicPINVOKE.TouchData_GetHitActor(swigCPtr, point), true);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public Vector2 GetLocalPosition(uint point) {
    Vector2 ret = new Vector2(NDalicPINVOKE.TouchData_GetLocalPosition(swigCPtr, point), false);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public Vector2 GetScreenPosition(uint point) {
    Vector2 ret = new Vector2(NDalicPINVOKE.TouchData_GetScreenPosition(swigCPtr, point), false);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public float GetRadius(uint point) {
    float ret = NDalicPINVOKE.TouchData_GetRadius(swigCPtr, point);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public Vector2 GetEllipseRadius(uint point) {
    Vector2 ret = new Vector2(NDalicPINVOKE.TouchData_GetEllipseRadius(swigCPtr, point), false);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public float GetPressure(uint point) {
    float ret = NDalicPINVOKE.TouchData_GetPressure(swigCPtr, point);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public Degree GetAngle(uint point) {
    Degree ret = new Degree(NDalicPINVOKE.TouchData_GetAngle(swigCPtr, point), true);
    if (NDalicPINVOKE.SWIGPendingException.Pending) throw NDalicPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
