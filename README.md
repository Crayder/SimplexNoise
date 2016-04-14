Simplex Noise
===============

Original repository author note:

	*Alternative to ci::Perlin class.*
	
	**This code is originally intended for use with the Cinder C++ library but only depends on GLM.**
	
	Simplex noise is better looking, faster and has proper derivatives without the grid artifacts of Perlin noise derivatives. This code is mostly ported from Stefan Gustavson public domain implementation for the simplex noise, simplex flow noise and their analytical derivatives. The curl noise functions are adapted from Robert Bridson papers to use derivatives instead of finite differences. There's also a series of noise sums and other multi-fractals noises...

And now, this has been ported to PAWN.

![](NoiseGallery.jpg)

```c++
//! Returns a 1D simplex noise
Float:noise1D(Float:x);
//! Returns a 2D simplex noise
Float:noise2D(Float:x, Float:y);
//! Returns a 3D simplex noise
Float:noise3D(Float:x, Float:y, Float:z);
//! Returns a 4D simplex noise
Float:noise4D(Float:x, Float:y, Float:z, Float:w);

//! Returns a 1D simplex ridged noise
Float:ridgedNoise1D(Float:x);
//! Returns a 2D simplex ridged noise
Float:ridgedNoise2D(Float:x, Float:y);
//! Returns a 3D simplex ridged noise
Float:ridgedNoise3D(Float:x, Float:y, Float:z);
//! Returns a 4D simplex ridged noise
Float:ridgedNoise4D(Float:x, Float:y, Float:z, Float:w);

//! Returns a 1D simplex noise with analytical derivative.
dnoise1D(Float:x, &Float:rx, &Float:ry)
//! Returns a 2D simplex noise with analytical derivatives.
dnoise2D(Float:x, Float:y, &Float:rx, &Float:ry, &Float:rz)
//! Returns a 3D simplex noise with analytical derivatives.
dnoise3D(Float:x, Float:y, Float:z, &Float:rx, &Float:ry, &Float:rz, &Float:rw)
//! Returns a 4D simplex noise with analytical derivatives (not PAWN yet)
// vec5	dnoise( const glm::vec4 &v );
	
//! Returns a 2D simplex cellular/worley noise
Float:worleyNoise2D(Float:x, Float:y)
//! Returns a 3D simplex cellular/worley noise
Float:worleyNoise3D(Float:x, Float:y, Float:z)
//! Returns a 2D simplex smooth cellular/worley noise
Float:worleyNoise2D_F(Float:x, Float:y, Float:falloff)
//! Returns a 3D simplex smooth cellular/worley noise
Float:worleyNoise3D_F(Float:x, Float:y, Float:z, Float:falloff)


/* None of the following is ported to PAWN yet
//! Returns a 2D simplex noise with rotating gradients
float flowNoise( const glm::vec2 &v, float angle );
//! Returns a 3D simplex noise with rotating gradients
float flowNoise( const glm::vec3 &v, float angle );

//! Returns a 2D simplex noise with rotating gradients and analytical derivatives
glm::vec3 dFlowNoise( const glm::vec2 &v, float angle );
//! Returns a 3D simplex noise with rotating gradients and analytical derivatives
glm::vec4 dFlowNoise( const glm::vec3 &v, float angle );

//! Returns the curl of a 2D simplex noise
glm::vec2 curlNoise( const glm::vec2 &v );
//! Returns the curl of a 2D simplex flow noise
glm::vec2 curlNoise( const glm::vec2 &v, float t );
//! Returns the curl of a 2D simplex noise fractal brownian motion sum
glm::vec2 curlNoise( const glm::vec2 &v, uint8_t octaves, float lacunarity, float gain );
//! Returns the curl of a 3D simplex noise
glm::vec3 curlNoise( const glm::vec3 &v );
//! Returns the curl of a 3D simplex flow noise
glm::vec3 curlNoise( const glm::vec3 &v, float t );
//! Returns the curl approximation of a 3D simplex noise fractal brownian motion sum
glm::vec3 curlNoise( const glm::vec3 &v, uint8_t octaves, float lacunarity, float gain );

//! Returns the curl of a custom 2D potential using finite difference approximation
glm::vec2 curl( const glm::vec2 &v, const std::function<float(const glm::vec2&)> &potential, float delta = 1e-4f );
//! Returns the curl of a custom 3D potential using finite difference approximation
glm::vec3 curl( const glm::vec3 &v, const std::function<glm::vec3(const glm::vec3&)> &potential, float delta = 1e-4f );

//! Returns a 1D simplex noise fractal brownian motion sum
float fBm( float x, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );
//! Returns a 2D simplex noise fractal brownian motion sum
float fBm( const glm::vec2 &v, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );
//! Returns a 3D simplex noise fractal brownian motion sum
float fBm( const glm::vec3 &v, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );
//! Returns a 4D simplex noise fractal brownian motion sum
float fBm( const glm::vec4 &v, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );

//! Returns a 1D simplex noise fractal brownian motion sum with analytical derivatives
glm::vec2 dfBm( float x, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );
//! Returns a 2D simplex noise fractal brownian motion sum with analytical derivatives
glm::vec3 dfBm( const glm::vec2 &v, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );
//! Returns a 3D simplex noise fractal brownian motion sum with analytical derivatives
glm::vec4 dfBm( const glm::vec3 &v, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );
//! Returns a 4D simplex noise fractal brownian motion sum with analytical derivatives
vec5	dfBm( const glm::vec4 &v, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );

//! Returns a 1D simplex ridged multi-fractal noise sum
float ridgedMF( float x, float ridgeOffset = 1.0f, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );
//! Returns a 2D simplex ridged multi-fractal noise sum
float ridgedMF( const glm::vec2 &v, float ridgeOffset = 1.0f, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );
//! Returns a 3D simplex ridged multi-fractal noise sum
float ridgedMF( const glm::vec3 &v, float ridgeOffset = 1.0f, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );
//! Returns a 4D simplex ridged multi-fractal noise sum
float ridgedMF( const glm::vec4 &v, float ridgeOffset = 1.0f, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );

//! Returns the 2D simplex noise fractal brownian motion sum variation by Iñigo Quilez
float iqfBm( const glm::vec2 &v, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );
//! Returns the 2D simplex noise fractal brownian motion sum variation by Iñigo Quilez
float iqfBm( const glm::vec3 &v, uint8_t octaves = 4, float lacunarity = 2.0f, float gain = 0.5f );

//! Returns the 2D simplex noise fractal brownian motion sum variation by Iñigo Quilez that use a mat2 to transform each octave
float iqMatfBm( const glm::vec2 &v, uint8_t octaves = 4, const glm::mat2 &mat = glm::mat2( 1.6, -1.2, 1.2, 1.6 ), float gain = 0.5f );
*/
```
