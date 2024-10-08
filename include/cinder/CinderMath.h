/*
 Copyright (c) 2010, The Barbarian Group
 All rights reserved.

 Portions Copyright (c) 2004, Laminar Research.

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and
	the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
	the following disclaimer in the documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "cinder/Cinder.h"
#include "cinder/CinderGlm.h"

#include <cmath>
#include <climits>
#include <cfloat>
#include <functional>
#if defined( CINDER_MSW )
	#undef min
	#undef max
#endif

namespace cinder {

template<typename T>
struct CI_API math
{
	static T	acos  (T x)		{return ::acos (double(x));}
	static T	asin  (T x)		{return ::asin (double(x));}
	static T	atan  (T x)		{return ::atan (double(x));}
	static T	atan2 (T y, T x)	{return ::atan2 (double(y), double(x));}
	static T	cos   (T x)		{return ::cos (double(x));}
	static T	sin   (T x)		{return ::sin (double(x));}
	static T	tan   (T x)		{return ::tan (double(x));}
	static T	cosh  (T x)		{return ::cosh (double(x));}
	static T	sinh  (T x)		{return ::sinh (double(x));}
	static T	tanh  (T x)		{return ::tanh (double(x));}
	static T	exp   (T x)		{return ::exp (double(x));}
	static T	log   (T x)		{return ::log (double(x));}
	static T	log10 (T x)		{return ::log10 (double(x));}
	static T	modf  (T x, T *iptr)
	{
		double ival;
		T rval( ::modf (double(x),&ival));
	*iptr = ival;
	return rval;
	}
	static T	pow   (T x, T y)	{return ::pow (double(x), double(y));}
	static T	sqrt  (T x)		{return ::sqrt (double(x));}
#if defined( _MSC_VER )
	static T	cbrt( T x )		{ return ( x > 0 ) ? (::pow( x, 1.0 / 3.0 )) : (- ::pow( -x, 1.0 / 3.0 ) ); }
#else
	static T	cbrt( T x )		{ return ::cbrt( x ); }
#endif
	static T	ceil  (T x)		{return ::ceil (double(x));}
	static T	abs  (T x)		{return ::fabs (double(x));}
	static T	floor (T x)		{return ::floor (double(x));}
	static T	fmod  (T x, T y)	{return ::fmod (double(x), double(y));}
	static T	hypot (T x, T y)	{return ::hypot (double(x), double(y));}
	static T	signum (T x)		{return ( x >0.0 ) ? 1.0 : ( ( x < 0.0 ) ? -1.0 : 0.0 ); }
	static T	min(T x, T y)				{return ( x < y ) ? x : y; }
	static T	max(T x, T y)				{return ( x > y ) ? x : y; }
	static T	clamp(T x, T min=0, T max=1)	{return ( x < min ) ? min : ( ( x > max ) ? max : x );}
};


template<>
struct CI_API math<float>
{
	static float	acos  (float x)			{return ::acosf (x);}
	static float	asin  (float x)			{return ::asinf (x);}
	static float	atan  (float x)			{return ::atanf (x);}
	static float	atan2 (float y, float x)	{return ::atan2f (y, x);}
	static float	cos   (float x)			{return ::cosf (x);}
	static float	sin   (float x)			{return ::sinf (x);}
	static float	tan   (float x)			{return ::tanf (x);}
	static float	cosh  (float x)			{return ::coshf (x);}
	static float	sinh  (float x)			{return ::sinhf (x);}
	static float	tanh  (float x)			{return ::tanhf (x);}
	static float	exp   (float x)			{return ::expf (x);}
	static float	log   (float x)			{return ::logf (x);}
	static float	log10 (float x)			{return ::log10f (x);}
	static float	modf  (float x, float *y)	{return ::modff (x, y);}
	static float	pow   (float x, float y)	{return ::powf (x, y);}
	static float	sqrt  (float x)			{return ::sqrtf (x);}
#if defined( _MSC_VER )
	static float	cbrt( float x )		{ return ( x > 0 ) ? (::powf( x, 1.0f / 3.0f )) : (- ::powf( -x, 1.0f / 3.0f ) ); }
#else
	static float	cbrt  (float x)			{ return ::cbrtf( x ); }	
#endif
	static float	ceil  (float x)			{return ::ceilf (x);}
	static float	abs   (float x)			{return ::fabsf (x);}
	static float	floor (float x)			{return ::floorf (x);}
	static float	fmod  (float x, float y)	{return ::fmodf (x, y);}
	#if !defined(_MSC_VER)
	static float	hypot (float x, float y)	{return ::hypotf (x, y);}
	#else
	static float hypot (float x, float y)	{return ::sqrtf(x*x + y*y);}
	#endif
	static float signum (float x)		{return ( x > 0.0f ) ? 1.0f : ( ( x < 0.0f ) ? -1.0f : 0.0f ); }
	static float min(float x, float y)					{return ( x < y ) ? x : y; }
	static float max(float x, float y)					{return ( x > y ) ? x : y; }
	static float clamp(float x, float min=0, float max=1)	{return ( x < min ) ? min : ( ( x > max ) ? max : x );}
};

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

constexpr double EPSILON_VALUE = 4.37114e-05;
#define EPSILON EPSILON_VALUE

CI_API inline bool approxZero( float n, float epsilon = float(EPSILON_VALUE) )
{
	return std::abs( n ) < epsilon;
}

CI_API inline bool approxZero( double n, double epsilon = EPSILON_VALUE )
{
	return std::abs( n ) < epsilon;
}

CI_API inline float roundToZero( float n, float epsilon = float(EPSILON_VALUE) )
{
	return approxZero( n, epsilon ) ? 0.0f : n;
}

CI_API inline double roundToZero( double n, double epsilon = EPSILON_VALUE )
{
	return approxZero( n, epsilon ) ? 0.0 : n;
}

CI_API inline bool approxEqual( float a, float b, float epsilon = float(EPSILON_VALUE) )
{
	return std::abs( b - a ) < epsilon;
}

CI_API inline bool approxEqual( double a, double b, double epsilon = EPSILON_VALUE )
{
	return std::abs( b - a ) < epsilon;
}

CI_API inline bool approxEqualRelative( float a, float b, float maxRelDiff = float(EPSILON_VALUE) )
{
	// See: https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/

	// Calculate the difference.
	const float diff = std::abs( a - b );

	// Find the largest.
	a = std::abs( a );
	b = std::abs( b );
	const float largest = ( b > a ) ? b : a;

	if( diff <= largest * maxRelDiff )
		return true;

	return false;
}

CI_API inline bool approxEqualRelative( double a, double b, double maxRelDiff = EPSILON_VALUE )
{
	// See: https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/

	// Calculate the difference.
	const double diff = std::abs( a - b );

	// Find the largest.
	a = std::abs( a );
	b = std::abs( b );
	const double largest = ( b > a ) ? b : a;

	if( diff <= largest * maxRelDiff )
		return true;

	return false;
}

inline float toRadians( float x )
{
	return x * 0.017453292519943295769f; // ( x * PI / 180 )
}

inline double toRadians( double x )
{
	return x * 0.017453292519943295769; // ( x * PI / 180 )
}

inline float toDegrees( float x )
{
	return x * 57.295779513082321f; // ( x * 180 / PI )
}

inline double toDegrees( double x )
{
	return x * 57.295779513082321; // ( x * 180 / PI )
}

template<typename T, typename L>
T lerp( const T &a, const T &b, L factor )
{
	return a + ( b - a ) * factor;
}

template<typename T>
T lmap(T val, T inMin, T inMax, T outMin, T outMax)
{
	return outMin + ((outMax - outMin) * (val - inMin)) / (inMax - inMin);
}

template<typename T, typename L>
T bezierInterp( T a, T b, T c, T d, L t)
{
    L t1 = static_cast<L>(1.0) - t;
    return a*(t1*t1*t1) + b*(3*t*t1*t1) + c*(3*t*t*t1) + d*(t*t*t);
}

template<typename T, typename L>
T bezierInterpRef( const T &a, const T &b, const T &c, const T &d, L t)
{
    L t1 = static_cast<L>(1.0) - t;
    return a*(t1*t1*t1) + b*(3*t*t1*t1) + c*(3*t*t*t1) + d*(t*t*t);
}

template<typename T>
T constrain( T val, T minVal, T maxVal )
{
	if( val < minVal ) return minVal;
	else if( val > maxVal ) return maxVal;
	else return val;
}

//! Returns the fractional part of \a x, calculated as `x - floor( x )`
template<typename T>
T fract( T x )
{
	return x - math<T>::floor( x );
}

// Don Hatch's version of sin(x)/x, which is accurate for very small x.
// Returns 1 for x == 0.
template <class T>
T sinx_over_x( T x )
{
    if( x * x < 1.19209290E-07F )
	return T( 1 );
    else
	return math<T>::sin( x ) / x;
}

// There are faster techniques for this, but this is portable
inline uint32_t log2floor( uint32_t x )
{
    uint32_t result = 0;
    while( x >>= 1 )
        ++result;

    return result;
}

inline uint32_t log2ceil( uint32_t x )
{
	uint32_t isNotPowerOf2 = (x & (x - 1));
	return ( isNotPowerOf2 ) ? (log2floor( x ) + 1) : log2floor( x );
}

inline uint32_t nextPowerOf2( uint32_t x )
{
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return(x+1);
}

//! Returns true if \a x is a power of two, false otherwise.
inline bool isPowerOf2( size_t x )
{
	return ( x & ( x - 1 ) ) == 0;
}

template<typename T>
inline int solveLinear( T a, T b, T result[1] )
{
	if( a == 0 ) return (b == 0 ? -1 : 0 );
	result[0] = -b / a;
	return 1;
}

template<typename T>
inline int solveQuadratic( T a, T b, T c, T result[2] )
{
	if( a == 0 ) return solveLinear( b, c, result );

	T radical = b * b - 4 * a * c;
	if( radical < 0 ) return 0;

	if( radical == 0 ) {
		result[0] = -b / (2 * a);
		return 1;
	}

	T srad = math<T>::sqrt( radical );
	result[0] = ( -b - srad ) / (2 * a);
	result[1] = ( -b + srad ) / (2 * a);
	if( a < 0 ) std::swap( result[0], result[1] );
	return 2;
}

template<typename T,int ORDER>
T rombergIntegral( T a, T b, const std::function<T(T)> &SPEEDFN )
{
	static_assert(ORDER > 2, "ORDER must be greater than 2" );
	T rom[2][ORDER];
	T half = b - a;

	rom[0][0] = ((T)0.5) * half * ( SPEEDFN(a)+SPEEDFN(b) );
	for( int i0=2, iP0=1; i0 <= ORDER; i0++, iP0 *= 2, half *= (T)0.5) {
		// approximations via the trapezoid rule
		T sum = 0;
		for( int i1 = 1; i1 <= iP0; i1++ )
			sum += SPEEDFN(a + half*(i1-((T)0.5)));

		// Richardson extrapolation
		rom[1][0] = ((T)0.5)*(rom[0][0] + half*sum);
		for( int i2 = 1, iP2 = 4; i2 < i0; i2++, iP2 *= 4 )
			rom[1][i2] = (iP2*rom[1][i2-1] - rom[0][i2-1])/(iP2-1);
		for( int i1 = 0; i1 < i0; i1++ )
			rom[0][i1] = rom[1][i1];
	}

	return rom[0][ORDER-1];
}

template<typename T>
CI_API int solveCubic( T a, T b, T c, T d, T result[3] );

//! Returns the closest point to \a testPoint on the boundary of the ellipse defined by \a center, \a axisA and \a axisB. Algorithm due to David Eberly, http://www.geometrictools.com/Documentation/DistancePointEllipseEllipsoid.pdf
CI_API glm::vec2 getClosestPointEllipse( const glm::vec2& center, const glm::vec2& axisA, const glm::vec2& axisB, const glm::vec2& testPoint );

//! Returns the closest point to \a testPoint on the line defined by the 2 \a controlPoints.
template<typename T>
CI_API glm::tvec2<T, glm::defaultp> getClosestPointLinear( const glm::tvec2<T, glm::defaultp> *controlPoints, const glm::tvec2<T, glm::defaultp> &testPoint );
//! Returns the closest point to \a testPoint on the line defined by the control points \a p0 and \a p1.
template<typename T>
glm::tvec2<T, glm::defaultp>		getClosestPointLinear( const glm::tvec2<T, glm::defaultp> &p0, const glm::tvec2<T, glm::defaultp> &p1, const glm::tvec2<T, glm::defaultp> &testPoint )
{
	glm::tvec2<T, glm::defaultp> controlPoints[] = { p0, p1 };
	return getClosestPointLinear<T>( controlPoints, testPoint );
}

//! Returns the closest point to \a testPoint on the quadratic curve defined by the 3 \a controlPoints. Algorithm due to Olivier Besson, http://blog.gludion.com/2009/08/distance-to-quadratic-bezier-curve.html
template<typename T>
CI_API glm::tvec2<T, glm::defaultp> getClosestPointQuadratic( const glm::tvec2<T, glm::defaultp> *controlPoints, const glm::tvec2<T, glm::defaultp> &testPoint );
//! Returns the closest point to \a testPoint on the quadratic curve defined by the control points \a p0, \a p1 and \a p2. Algorithm due to Olivier Besson, http://blog.gludion.com/2009/08/distance-to-quadratic-bezier-curve.html
template<typename T>
glm::tvec2<T, glm::defaultp>		getClosestPointQuadratic( const glm::tvec2<T, glm::defaultp> &p0, const glm::tvec2<T, glm::defaultp> &p1, const glm::tvec2<T, glm::defaultp> &p2, const glm::tvec2<T, glm::defaultp> &testPoint )
{
	glm::tvec2<T, glm::defaultp> controlPoints[] = { p0, p1, p2 };
	return getClosestPointQuadratic<T>( controlPoints, testPoint );
}

//! Returns the closest point to \a testPoint on the cubic curve defined by the 4 \a controlPoints. Algorithm due to Philip J. Schneider, https://github.com/erich666/GraphicsGems/blob/master/gems/NearestPoint.c
template<typename T>
CI_API glm::tvec2<T, glm::defaultp> getClosestPointCubic( const glm::tvec2<T, glm::defaultp> *controlPoints, const glm::tvec2<T, glm::defaultp> &testPoint );
//! Returns the closest point to \a testPoint on the cubic curve defined by the control points \a p0, \a p1, \a p2 and \a p3. Algorithm due to Philip J. Schneider, https://github.com/erich666/GraphicsGems/blob/master/gems/NearestPoint.c
template<typename T>
glm::tvec2<T, glm::defaultp>		getClosestPointCubic( const glm::tvec2<T, glm::defaultp> &p0, const glm::tvec2<T, glm::defaultp> &p1, const glm::tvec2<T, glm::defaultp> &p2, const glm::tvec2<T, glm::defaultp> &p3, const glm::tvec2<T, glm::defaultp> &testPoint )
{
	glm::tvec2<T, glm::defaultp> controlPoints[] = { p0, p1, p2, p3 };
	return getClosestPointCubic<T>( controlPoints, testPoint );
}

union half_float
{
	uint16_t u;
	struct {
		uint16_t Mantissa : 10;
		uint16_t Exponent : 5;
		uint16_t Sign : 1;
	};
};

CI_API half_float floatToHalf( float f );
CI_API float halfToFloat( half_float h );

} // namespace cinder

#if defined( _MSC_VER ) && ( _MSC_VER < 1800 )
// define math.h functions that aren't defined until vc120
namespace std {

inline bool isfinite( float arg )	{ return _finite( arg ) != 0; }
inline bool isfinite( double arg )	{ return _finite( arg ) != 0; }
inline bool isnan( float arg )		{ return _isnan( arg ) != 0; }
inline bool isnan( double arg )		{ return _isnan( arg ) != 0; }

// note that while these round* variants follow the basic premise of c99 implementations (numbers with fractional parts of 0.5 should be
// rounded away from zero), they are not 100% compliable implementations since they do not cover all edge cases like NaN's, inifinite numbers, etc.
inline double	round( double x )	{ return floor( x < 0 ? x - 0.5 : x + 0.5 ); }
inline float	roundf( float x )	{ return floorf( x < 0 ? x - 0.5f : x + 0.5f );	}
inline long int lround( double x )	{ return (long int)( x < 0 ? x - 0.5 : x + 0.5 ); }
inline long int lroundf( float x )	{ return (long int)( x < 0 ? x - 0.5f : x + 0.5f );	}

} // namespace std
#endif // defined( _MSC_VER ) && ( _MSC_VER < 1800 )
