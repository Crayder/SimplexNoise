/*
 Simplex Noise
 
 Copyright (c) 2016, Simon Geilfus, All rights reserved.
 Code adapted from Stefan Gustavson Simplex Noise Public Domain implementation
 Curl noise adapted from Robert Bridson papers
 This code also includes variation of noise sums by Iñigo Quilez
 
 Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 the following conditions are met:
 
 * Redistributions of source code must retain the above copyright notice, this list of conditions and
	the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
	the following disclaimer in the documentation and / or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
*/

/*
//! Returns a 1D simplex noise
Float:noise(Float:x);
//! Returns a 2D simplex noise
Float:noise(const vec2 &v);
//! Returns a 3D simplex noise
Float:noise(const vec3 &v);
//! Returns a 4D simplex noise
Float:noise(const vec4 &v);

//! Returns a 1D simplex ridged noise
Float:ridgedNoise(Float:x);
//! Returns a 2D simplex ridged noise
Float:ridgedNoise(const vec2 &v);
//! Returns a 3D simplex ridged noise
Float:ridgedNoise(const vec3 &v);
//! Returns a 4D simplex ridged noise
Float:ridgedNoise(const vec4 &v);

//! Returns a 1D simplex noise with analytical derivative.
vec2 dnoise(Float:x);
//! Returns a 2D simplex noise with analytical derivatives.
vec3 dnoise(const vec2 &v);
//! Returns a 3D simplex noise with analytical derivatives.
vec4 dnoise(const vec3 &v);
// not optimal but easiest way to return 5 floats
typedef std::array < float,5 > vec5;
//! Returns a 4D simplex noise with analytical derivatives
vec5	dnoise(const vec4 &v);
	
//! Returns a 2D simplex cellular / worley noise
Float:worleyNoise(const vec2 &v);
//! Returns a 3D simplex cellular / worley noise
Float:worleyNoise(const vec3 &v);
//! Returns a 2D simplex smooth cellular / worley noise
Float:worleyNoise(const vec2 &v, Float:falloff);
//! Returns a 3D simplex smooth cellular / worley noise
Float:worleyNoise(const vec3 &v, Float:falloff);

//! Returns a 2D simplex noise with rotating gradients
Float:flowNoise(const vec2 &v, Float:angle);
//! Returns a 3D simplex noise with rotating gradients
Float:flowNoise(const vec3 &v, Float:angle);

//! Returns a 2D simplex noise with rotating gradients and analytical derivatives
vec3 dFlowNoise(const vec2 &v, Float:angle);
//! Returns a 3D simplex noise with rotating gradients and analytical derivatives
vec4 dFlowNoise(const vec3 &v, Float:angle);

//! Returns the curl of a 2D simplex noise
vec2 curlNoise(const vec2 &v);
//! Returns the curl of a 2D simplex flow noise
vec2 curlNoise(const vec2 &v, Float:t);
//! Returns the curl of a 2D simplex noise fractal brownian motion sum
vec2 curlNoise(const vec2 &v, uint8_t octaves, Float:lacunarity, Float:gain);
//! Returns the curl of a 3D simplex noise
vec3 curlNoise(const vec3 &v);
//! Returns the curl of a 3D simplex flow noise
vec3 curlNoise(const vec3 &v, Float:t);
//! Returns the curl approximation of a 3D simplex noise fractal brownian motion sum
vec3 curlNoise(const vec3 &v, uint8_t octaves, Float:lacunarity, Float:gain);

//! Returns the curl of a custom 2D potential using finite difference approximation
vec2 curl(const vec2 &v, const std::function < float(const vec2&)> &potential, Float:delta = 1e - 4);
//! Returns the curl of a custom 3D potential using finite difference approximation
vec3 curl(const vec3 &v, const std::function < vec3(const vec3&)> &potential, Float:delta = 1e - 4);

//! Returns a 1D simplex noise fractal brownian motion sum
Float:fBm(Float:x, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 2D simplex noise fractal brownian motion sum
Float:fBm(const vec2 &v, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 3D simplex noise fractal brownian motion sum
Float:fBm(const vec3 &v, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 4D simplex noise fractal brownian motion sum
Float:fBm(const vec4 &v, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
	
//! Returns a 2D simplex cellular / worley noise fractal brownian motion sum
Float:worleyfBm(const vec2 &v, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 3D simplex cellular / worley noise fractal brownian motion sum
Float:worleyfBm(const vec3 &v, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 2D simplex smooth cellular / worley noise fractal brownian motion sum
Float:worleyfBm(const vec2 &v, Float:falloff, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 3D simplex smooth cellular / worley noise fractal brownian motion sum
Float:worleyfBm(const vec3 &v, Float:falloff, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);

//! Returns a 1D simplex noise fractal brownian motion sum with analytical derivatives
vec2 dfBm(Float:x, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 2D simplex noise fractal brownian motion sum with analytical derivatives
vec3 dfBm(const vec2 &v, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 3D simplex noise fractal brownian motion sum with analytical derivatives
vec4 dfBm(const vec3 &v, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 4D simplex noise fractal brownian motion sum with analytical derivatives
vec5	dfBm(const vec4 &v, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
	
//! Returns a 1D simplex ridged multi - fractal noise sum
Float:ridgedMF(Float:x, Float:ridgeOffset = 1.0, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 2D simplex ridged multi - fractal noise sum
Float:ridgedMF(const vec2 &v, Float:ridgeOffset = 1.0, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 3D simplex ridged multi - fractal noise sum
Float:ridgedMF(const vec3 &v, Float:ridgeOffset = 1.0, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns a 4D simplex ridged multi - fractal noise sum
Float:ridgedMF(const vec4 &v, Float:ridgeOffset = 1.0, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);

//! Returns the 2D simplex noise fractal brownian motion sum variation by Iñigo Quilez
Float:iqfBm(const vec2 &v, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);
//! Returns the 2D simplex noise fractal brownian motion sum variation by Iñigo Quilez
Float:iqfBm(const vec3 &v, uint8_t octaves = 4, Float:lacunarity = 2.0, Float:gain = 0.5);

//! Returns the 2D simplex noise fractal brownian motion sum variation by Iñigo Quilez that use a mat2 to transform each octave
Float:iqMatfBm(const vec2 &v, uint8_t octaves = 4, const mat2 &mat = mat2(1.6, - 1.2, 1.2, 1.6), Float:gain = 0.5);
*/
	
	
// implementation
	
#define FASTFLOOR(%0) (((%0)> 0) ? floatround(%0) : (floatround(%0)- 1))

/*
 * Permutation table. This is just a random jumble of all numbers 0 - 255,
 * repeated twice to avoid wrapping the index at 255 for each lookup.
 * This needs to be exactly the same for all instances on all platforms,
 * so it's easiest to just keep it as static explicit data.
 * This also removes the need for any initialisation of this class.
 *
 * Note that making this an int[] instead of a char[] might make the
 * code run faster on platforms with a high penalty for unaligned single
 * byte addressing. Intel x86 is generally single - byte - friendly, but
 * some other CPUs are faster with 4 - aligned reads.
 * However, a char[] is smaller, which avoids cache trashing, and that
 * is probably the most important aspect on most architectures.
 * This array is accessed a * lot * by the noise functions.
 * A vector - valued noise over 3D accesses it 96 times, and a
 * float - valued 4D noise 64 times. We want this to fit in the cache!
 */
	
static perm[512] = {
    151, 160, 137,  91,  90,  15, 131,  13, 201,  95,  96,  53, 194, 233,   7, 225,
    140,  36, 103,  30,  69, 142,   8,  99,  37, 240,  21,  10,  23, 190,   6, 148,
    247, 120, 234,  75,   0,  26, 197,  62,  94, 252, 219, 203, 117,  35,  11,  32,
     57, 177,  33,  88, 237, 149,  56,  87, 174,  20, 125, 136, 171, 168,  68, 175,
     74, 165,  71, 134, 139,  48,  27, 166,  77, 146, 158, 231,  83, 111, 229, 122,
     60, 211, 133, 230, 220, 105,  92,  41,  55,  46, 245,  40, 244, 102, 143,  54,
     65,  25,  63, 161,   1, 216,  80,  73, 209,  76, 132, 187, 208,  89,  18, 169,
    200, 196, 135, 130, 116, 188, 159,  86, 164, 100, 109, 198, 173, 186,   3,  64,
     52, 217, 226, 250, 124, 123,   5, 202,  38, 147, 118, 126, 255,  82,  85, 212,
    207, 206,  59, 227,  47,  16,  58,  17, 182, 189,  28,  42, 223, 183, 170, 213,
    119, 248, 152,   2,  44, 154, 163,  70, 221, 153, 101, 155, 167,  43, 172,   9,
    129,  22,  39, 253,  19,  98, 108, 110,  79, 113, 224, 232, 178, 185, 112, 104,
    218, 246,  97, 228, 251,  34, 242, 193, 238, 210, 144,  12, 191, 179, 162, 241,
     81,  51, 145, 235, 249,  14, 239, 107,  49, 192, 214,  31, 181, 199, 106, 157,
    184,  84, 204, 176, 115, 121,  50,  45, 127,   4, 150, 254, 138, 236, 205,  93,
    222, 114,  67,  29,  24,  72, 243, 141, 128, 195,  78,  66, 215,  61, 156, 180,
    151, 160, 137,  91,  90,  15, 131,  13, 201,  95,  96,  53, 194, 233,   7, 225,
    140,  36, 103,  30,  69, 142,   8,  99,  37, 240,  21,  10,  23, 190,   6, 148,
    247, 120, 234,  75,   0,  26, 197,  62,  94, 252, 219, 203, 117,  35,  11,  32,
     57, 177,  33,  88, 237, 149,  56,  87, 174,  20, 125, 136, 171, 168,  68, 175,
     74, 165,  71, 134, 139,  48,  27, 166,  77, 146, 158, 231,  83, 111, 229, 122,
     60, 211, 133, 230, 220, 105,  92,  41,  55,  46, 245,  40, 244, 102, 143,  54,
     65,  25,  63, 161,   1, 216,  80,  73, 209,  76, 132, 187, 208,  89,  18, 169,
    200, 196, 135, 130, 116, 188, 159,  86, 164, 100, 109, 198, 173, 186,   3,  64,
     52, 217, 226, 250, 124, 123,   5, 202,  38, 147, 118, 126, 255,  82,  85, 212,
    207, 206,  59, 227,  47,  16,  58,  17, 182, 189,  28,  42, 223, 183, 170, 213,
    119, 248, 152,   2,  44, 154, 163,  70, 221, 153, 101, 155, 167,  43, 172,   9,
    129,  22,  39, 253,  19,  98, 108, 110,  79, 113, 224, 232, 178, 185, 112, 104,
    218, 246,  97, 228, 251,  34, 242, 193, 238, 210, 144,  12, 191, 179, 162, 241,
     81,  51, 145, 235, 249,  14, 239, 107,  49, 192, 214,  31, 181, 199, 106, 157,
    184,  84, 204, 176, 115, 121,  50,  45, 127,   4, 150, 254, 138, 236, 205,  93,
    222, 114,  67,  29,  24,  72, 243, 141, 128, 195,  78,  66, 215,  61, 156, 180
};

/*
* Gradient tables. These could be programmed the Ken Perlin way with
* some clever bit - twiddling, but this is more clear, and not really slower.
*/
static Float:grad2lut[8][2] = {
    { - 1.0, - 1.0 }, { 1.0, 0.0 } , { - 1.0, 0.0 } , { 1.0, 1.0 } ,
    { - 1.0, 1.0 } , { 0.0, - 1.0 } , { 0.0, 1.0 } , { 1.0, - 1.0 }
};

/*
* Gradient directions for 3D.
* These vectors are based on the midpoints of the 12 edges of a cube.
* A larger array of random unit length vectors would also do the job,
* but these 12 (including 4 repeats to make the array length a power
* of two) work better. They are not random, they are carefully chosen
* to represent a small, isotropic set of directions.
*/

static Float:grad3lut[16][3] = {
    { 1.0, 0.0, 1.0 }, { 0.0, 1.0, 1.0 }, // 12 cube edges
    { - 1.0, 0.0, 1.0 }, { 0.0, - 1.0, 1.0 },
    { 1.0, 0.0, - 1.0 }, { 0.0, 1.0, - 1.0 },
    { - 1.0, 0.0, - 1.0 }, { 0.0, - 1.0, - 1.0 },
    { 1.0, - 1.0, 0.0 }, { 1.0, 1.0, 0.0 },
    { - 1.0, 1.0, 0.0 }, { - 1.0, - 1.0, 0.0 },
    { 1.0, 0.0, 1.0 }, { - 1.0, 0.0, 1.0 }, // 4 repeats to make 16
    { 0.0, 1.0, - 1.0 }, { 0.0, - 1.0, - 1.0 }
};

static Float:grad4lut[32][4] = {
    { 0.0, 1.0, 1.0, 1.0 }, { 0.0, 1.0, 1.0, - 1.0 }, { 0.0, 1.0, - 1.0, 1.0 }, { 0.0, 1.0, - 1.0, - 1.0 }, // 32 tesseract edges
    { 0.0, - 1.0, 1.0, 1.0 }, { 0.0, - 1.0, 1.0, - 1.0 }, { 0.0, - 1.0, - 1.0, 1.0 }, { 0.0, - 1.0, - 1.0, - 1.0 },
    { 1.0, 0.0, 1.0, 1.0 }, { 1.0, 0.0, 1.0, - 1.0 }, { 1.0, 0.0, - 1.0, 1.0 }, { 1.0, 0.0, - 1.0, - 1.0 },
    { - 1.0, 0.0, 1.0, 1.0 }, { - 1.0, 0.0, 1.0, - 1.0 }, { - 1.0, 0.0, - 1.0, 1.0 }, { - 1.0, 0.0, - 1.0, - 1.0 },
    { 1.0, 1.0, 0.0, 1.0 }, { 1.0, 1.0, 0.0, - 1.0 }, { 1.0, - 1.0, 0.0, 1.0 }, { 1.0, - 1.0, 0.0, - 1.0 },
    { - 1.0, 1.0, 0.0, 1.0 }, { - 1.0, 1.0, 0.0, - 1.0 }, { - 1.0, - 1.0, 0.0, 1.0 }, { - 1.0, - 1.0, 0.0, - 1.0 },
    { 1.0, 1.0, 1.0, 0.0 }, { 1.0, 1.0, - 1.0, 0.0 }, { 1.0, - 1.0, 1.0, 0.0 }, { 1.0, - 1.0, - 1.0, 0.0 },
    { - 1.0, 1.0, 1.0, 0.0 }, { - 1.0, 1.0, - 1.0, 0.0 }, { - 1.0, - 1.0, 1.0, 0.0 }, { - 1.0, - 1.0, - 1.0, 0.0 }
};

/*
* For 3D, we define two orthogonal vectors in the desired rotation plane.
* These vectors are based on the midpoints of the 12 edges of a cube,
* they all rotate in their own plane and are never coincident or collinear.
* A larger array of random vectors would also do the job, but these 12
* (including 4 repeats to make the array length a power of two) work better.
* They are not random, they are carefully chosen to represent a small
* isotropic set of directions for any rotation angle.
*/

/* a = sqrt(2)/ sqrt(3) = 0.816496580 */
#define a 0.81649658

static Float:grad3u[16][3] = {
    { 1.0, 0.0, 1.0 }, { 0.0, 1.0, 1.0 }, // 12 cube edges
    { - 1.0, 0.0, 1.0 }, { 0.0, - 1.0, 1.0 },
    { 1.0, 0.0, - 1.0 }, { 0.0, 1.0, - 1.0 },
    { - 1.0, 0.0, - 1.0 }, { 0.0, - 1.0, - 1.0 },
    { a, a, a }, { - a, a, - a },
    { - a, - a, a }, { a, - a, - a },
    { - a, a, a }, { a, - a, a },
    { a, - a, - a }, { - a, a, - a }
};

static Float:grad3v[16][3] = {
    { - a, a, a }, { - a, - a, a },
    { a, - a, a }, { a, a, a },
    { - a, - a, - a }, { a, - a, - a },
    { a, a, - a }, { - a, a, - a },
    { 1.0, - 1.0, 0.0 }, { 1.0, 1.0, 0.0 },
    { - 1.0, 1.0, 0.0 }, { - 1.0, - 1.0, 0.0 },
    { 1.0, 0.0, 1.0 }, { - 1.0, 0.0, 1.0 }, // 4 repeats to make 16
    { 0.0, 1.0, - 1.0 }, { 0.0, - 1.0, - 1.0 }
};

#undef a


//---------------------------------------------------------------------

/*
* Helper functions to compute gradients - dot - residualvectors (1D to 4D)
* Note that these generate gradients of more than unit length. To make
* a close match with the value range of classic Perlin noise, the final
* noise values need to be rescaled to fit nicely within [- 1,1].
* (The simplex noise functions as such also have different scaling.)
* Note also that these noise functions are the most practical and useful
* signed version of Perlin noise. To return values according to the
* RenderMan specification from the SL noise() and pnoise() functions,
* the noise values need to be scaled and offset to [0,1], like this:
* Float:SLnoise = (SimplexNoise1234::noise(x,y,z) + 1.0) * 0.5;
*/

stock Float:grad1D(hash, Float:x) {
    new h = hash & 15;
    new Float:grad = 1.0 + (h & 7);   // Gradient value 1.0, 2.0, ..., 8.0
    if(h & 8) grad = - grad;         // Set a random sign for the gradient
    return (grad * x);           // Multiply the gradient with the distance
}

stock Float:grad2D(hash, Float:x, Float:y) {
    new h = hash & 7;      // Convert low 3 bits of hash code
    new Float:u = h < 4 ? x : y;  // into 8 simple gradient directions,
    new Float:v = h < 4 ? y : x;  // and compute the dot product with (x,y).
    return ((h & 1) ? - u : u) + ((h & 2) ? - 2.0 * v : 2.0 * v);
}

stock Float:grad3D(hash, Float:x, Float:y , Float:z) {
    new h = hash & 15;     // Convert low 4 bits of hash code into 12 simple
    new Float:u = h < 8 ? x : y; // gradient directions, and compute dot product.
    new Float:v = h < 4 ? y : h == 12 || h == 14 ? x : z; // Fix repeats at h = 12 to 15
    return ((h&1)? - u : u) + ((h&2)? - v : v);
}

stock Float:grad4D(hash, Float:x, Float:y, Float:z, Float:t) {
    new h = hash & 31;      // Convert low 5 bits of hash code into 32 simple
    new Float:u = h < 24 ? x : y; // gradient directions, and compute dot product.
    new Float:v = h < 16 ? y : z;
    new Float:w = h < 8 ? z : t;
    return ((h & 1) ? - u : u) + ((h & 2) ? - v : v) + ((h & 4) ? - w : w);
}

/*
* Helper functions to compute gradients in 1D to 4D
* and gradients - dot - residualvectors in 2D to 4D.
*/

stock grad1(hash, &Float:gx) {
    new h = hash & 15;
    gx = 1.0 + (h & 7);   // Gradient value is one of 1.0, 2.0, ..., 8.0
    if(h & 8) gx = - gx;   // Make half of the gradients negative
}

stock grad2(hash, &Float:gx, &Float:gy) {
    new h = hash & 7;
    gx = grad2lut[h][0];
    gy = grad2lut[h][1];
}

stock grad3(hash, &Float:gx, &Float:gy, &Float:gz) {
    new h = hash & 15;
    gx = grad3lut[h][0];
    gy = grad3lut[h][1];
    gz = grad3lut[h][2];
}

stock grad4(hash, &Float:gx, &Float:gy, &Float:gz, &Float:gw) {
    new h = hash & 31;
    gx = grad4lut[h][0];
    gy = grad4lut[h][1];
    gz = grad4lut[h][2];
    gw = grad4lut[h][3];
}


/*
* Helper functions to compute rotated gradients and
* gradients - dot - residualvectors in 2D and 3D.
*/

stock gradrot2(hash, Float:sin_t, Float:cos_t, &Float:gx, &Float:gy) {
    new h = hash & 7;
    new Float:gx0 = grad2lut[h][0];
    new Float:gy0 = grad2lut[h][1];
    gx = cos_t * gx0 - sin_t * gy0;
    gy = sin_t * gx0 + cos_t * gy0;
}

stock gradrot3(hash, Float:sin_t, Float:cos_t, &Float:gx, &Float:gy, &Float:gz) {
    new h = hash & 15;
    new Float:gux = grad3u[h][0];
    new Float:guy = grad3u[h][1];
    new Float:guz = grad3u[h][2];
    new Float:gvx = grad3v[h][0];
    new Float:gvy = grad3v[h][1];
    new Float:gvz = grad3v[h][2];
    gx = cos_t * gux + sin_t * gvx;
    gy = cos_t * guy + sin_t * gvy;
    gz = cos_t * guz + sin_t * gvz;
}

stock Float:graddotp2(Float:gx, Float:gy, Float:x, Float:y) {
    return gx * x + gy * y;
}

stock Float:graddotp3(Float:gx, Float:gy, Float:gz, Float:x, Float:y, Float:z) {
    return gx * x + gy * y + gz * z;
}

/* Skewing factors for 2D simplex grid:
 * F2 = 0.5 *(sqrt(3.0)- 1.0)
 * G2 = (3.0 -Math.sqrt(3.0))/ 6.0
 */
 
#define F2 0.366025403
#define G2 0.211324865

/* Skewing factors for 3D simplex grid:
 * F3 = 1 / 3
 * G3 = 1 / 6 */
 
#define F3 0.333333333
#define G3 0.166666667


// The skewing and unskewing factors are hairy again for the 4D case

#define F4 0.309016994 // F4 = (Math.sqrt(5.0)- 1.0)/ 4.0
#define G4 0.138196601 // G4 = (5.0 -Math.sqrt(5.0))/ 20.0

stock Float:noise1D(Float:x)
{
    new i0 = FASTFLOOR(x);
    new i1 = i0 + 1;
    new Float:x0 = x - i0;
    new Float:x1 = x0 - 1.0;

    new Float:n0, Float:n1;

    new Float:t0 = 1.0 - x0 * x0;
    //  if(t0 < 0.0) t0 = 0.0;
    t0 *= t0;
    n0 = t0 * t0 * grad1D(perm[i0 & 0xff], x0);

    new Float:t1 = 1.0 - x1 * x1;
    //  if(t1 < 0.0) t1 = 0.0;
    t1 *= t1;
    n1 = t1 * t1 * grad1D(perm[i1 & 0xff], x1);
    // The maximum value of this noise is 8 *(3 / 4)^4 = 2.53125
    // A factor of 0.395 would scale to fit exactly within [- 1,1], but
    // we want to match PRMan's 1D noise, so we scale it down some more.
    return 0.25 * (n0 + n1);
}

// 2D simplex noise
stock Float:noise2D(Float:x, Float:y)
{
    new Float:n0, Float:n1, Float:n2; // Noise contributions from the three corners

    // Skew the input space to determine which simplex cell we're in
    new Float:s = (x + y)*F2; // Hairy factor for 2D
    new Float:xs = x + s;
    new Float:ys = y + s;
    new i = FASTFLOOR(xs);
    new j = FASTFLOOR(ys);

    new Float:t = float(i + j)*G2;
    new Float:X0 = i - t; // Unskew the cell origin back to (x,y) space
    new Float:Y0 = j - t;
    new Float:x0 = x -X0; // The x,y distances from the cell origin
    new Float:y0 = y -Y0;

    // For the 2D case, the simplex shape is an equilateral triangle.
    // Determine which simplex we are in.
    new i1, j1; // Offsets for second (middle) corner of simplex in (i,j) coords
    if(x0 > y0) {i1 = 1; j1 = 0;} // lower triangle, XY order: (0,0)->(1,0)->(1,1)
    else {i1 = 0; j1 = 1;}      // upper triangle, YX order: (0,0)->(0,1)->(1,1)

    // A step of (1,0) in (i,j) means a step of (1 - c,- c) in (x,y), and
    // a step of (0,1) in (i,j) means a step of (- c,1 - c) in (x,y), where
    // c = (3 - sqrt(3))/ 6

    new Float:x1 = x0 - i1 + G2; // Offsets for middle corner in (x,y) unskewed coords
    new Float:y1 = y0 - j1 + G2;
    new Float:x2 = x0 - 1.0 + 2.0 * G2; // Offsets for last corner in (x,y) unskewed coords
    new Float:y2 = y0 - 1.0 + 2.0 * G2;

    // Wrap the integer indices at 256, to avoid indexing perm[] out of bounds
    new ii = i & 0xff;
    new jj = j & 0xff;

    // Calculate the contribution from the three corners
    new Float:t0 = 0.5 - x0 * x0 - y0 * y0;
    if(t0 < 0.0) n0 = 0.0;
    else {
        t0 *= t0;
        n0 = t0 * t0 * grad2D(perm[ii + perm[jj]], x0, y0);
    }

    new Float:t1 = 0.5 - x1 * x1 - y1 * y1;
    if(t1 < 0.0) n1 = 0.0;
    else {
        t1 *= t1;
        n1 = t1 * t1 * grad2D(perm[ii + i1 + perm[jj + j1]], x1, y1);
    }

    new Float:t2 = 0.5 - x2 * x2 - y2 * y2;
    if(t2 < 0.0) n2 = 0.0;
    else {
        t2 *= t2;
        n2 = t2 * t2 * grad2D(perm[ii + 1 + perm[jj + 1]], x2, y2);
    }

    // Add contributions from each corner to get the final noise value.
    // The result is scaled to return values in the interval [- 1,1].
    return 40.0 * (n0 + n1 + n2); // TODO: The scale factor is preliminary!
}

// 3D simplex noise
stock Float:noise3D(Float:x, Float:y, Float:z)
{
    new Float:n0, Float:n1, Float:n2, Float:n3; // Noise contributions from the four corners

    // Skew the input space to determine which simplex cell we're in
    new Float:s = (x + y + z)*F3; // Very nice and simple skew factor for 3D
    new Float:xs = x + s;
    new Float:ys = y + s;
    new Float:zs = z + s;
    new i = FASTFLOOR(xs);
    new j = FASTFLOOR(ys);
    new k = FASTFLOOR(zs);

    new Float:t = float(i + j + k)*G3;
    new Float:X0 = i - t; // Unskew the cell origin back to (x,y,z) space
    new Float:Y0 = j - t;
    new Float:Z0 = k - t;
    new Float:x0 = x -X0; // The x,y,z distances from the cell origin
    new Float:y0 = y -Y0;
    new Float:z0 = z -Z0;

    // For the 3D case, the simplex shape is a slightly irregular tetrahedron.
    // Determine which simplex we are in.
    new i1, j1, k1; // Offsets for second corner of simplex in (i,j,k) coords
    new i2, j2, k2; // Offsets for third corner of simplex in (i,j,k) coords

    /* This code would benefit from a backport from the GLSL version! */
    if(x0 >= y0) {
        if(y0 >= z0)
        { i1 = 1; j1 = 0; k1 = 0; i2 = 1; j2 = 1; k2 = 0; } // X Y Z order
        else if(x0 >= z0) { i1 = 1; j1 = 0; k1 = 0; i2 = 1; j2 = 0; k2 = 1; } // X Z Y order
        else { i1 = 0; j1 = 0; k1 = 1; i2 = 1; j2 = 0; k2 = 1; } // Z X Y order
    }
    else { // x0 < y0
        if(y0 < z0) { i1 = 0; j1 = 0; k1 = 1; i2 = 0; j2 = 1; k2 = 1; } // Z Y X order
        else if(x0 < z0) { i1 = 0; j1 = 1; k1 = 0; i2 = 0; j2 = 1; k2 = 1; } // Y Z X order
        else { i1 = 0; j1 = 1; k1 = 0; i2 = 1; j2 = 1; k2 = 0; } // Y X Z order
    }

    // A step of (1,0,0) in (i,j,k) means a step of (1 - c,- c,- c) in (x,y,z),
    // a step of (0,1,0) in (i,j,k) means a step of (- c,1 - c,- c) in (x,y,z), and
    // a step of (0,0,1) in (i,j,k) means a step of (- c,- c,1 - c) in (x,y,z), where
    // c = 1 / 6.

    new Float:x1 = x0 - i1 + G3; // Offsets for second corner in (x,y,z) coords
    new Float:y1 = y0 - j1 + G3;
    new Float:z1 = z0 - k1 + G3;
    new Float:x2 = x0 - i2 + 2.0 *G3; // Offsets for third corner in (x,y,z) coords
    new Float:y2 = y0 - j2 + 2.0 *G3;
    new Float:z2 = z0 - k2 + 2.0 *G3;
    new Float:x3 = x0 - 1.0 + 3.0 *G3; // Offsets for last corner in (x,y,z) coords
    new Float:y3 = y0 - 1.0 + 3.0 *G3;
    new Float:z3 = z0 - 1.0 + 3.0 *G3;

    // Wrap the integer indices at 256, to avoid indexing perm[] out of bounds
    new ii = i & 0xff;
    new jj = j & 0xff;
    new kk = k & 0xff;

    // Calculate the contribution from the four corners
    new Float:t0 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0;
    if(t0 < 0.0) n0 = 0.0;
    else {
        t0 *= t0;
        n0 = t0 * t0 * grad3D(perm[ii + perm[jj + perm[kk]]], x0, y0, z0);
    }

    new Float:t1 = 0.6 - x1 * x1 - y1 * y1 - z1 * z1;
    if(t1 < 0.0) n1 = 0.0;
    else {
        t1 *= t1;
        n1 = t1 * t1 * grad3D(perm[ii + i1 + perm[jj + j1 + perm[kk + k1]]], x1, y1, z1);
    }

    new Float:t2 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2;
    if(t2 < 0.0) n2 = 0.0;
    else {
        t2 *= t2;
        n2 = t2 * t2 * grad3D(perm[ii + i2 + perm[jj + j2 + perm[kk + k2]]], x2, y2, z2);
    }

    new Float:t3 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3;
    if(t3 < 0.0) n3 = 0.0;
    else {
        t3 *= t3;
        n3 = t3 * t3 * grad3D(perm[ii + 1 + perm[jj + 1 + perm[kk + 1]]], x3, y3, z3);
    }

    // Add contributions from each corner to get the final noise value.
    // The result is scaled to stay just inside [- 1,1]
    return 32.0 * (n0 + n1 + n2 + n3); // TODO: The scale factor is preliminary!
}

static sSimplexLut[64][4] = {
    {0,1,2,3},{0,1,3,2},{0,0,0,0},{0,2,3,1},{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,2,3,0},
    {0,2,1,3},{0,0,0,0},{0,3,1,2},{0,3,2,1},{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,3,2,0},
    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
    {1,2,0,3},{0,0,0,0},{1,3,0,2},{0,0,0,0},{0,0,0,0},{0,0,0,0},{2,3,0,1},{2,3,1,0},
    {1,0,2,3},{1,0,3,2},{0,0,0,0},{0,0,0,0},{0,0,0,0},{2,0,3,1},{0,0,0,0},{2,1,3,0},
    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
    {2,0,1,3},{0,0,0,0},{0,0,0,0},{0,0,0,0},{3,0,1,2},{3,0,2,1},{0,0,0,0},{3,1,2,0},
    {2,1,0,3},{0,0,0,0},{0,0,0,0},{0,0,0,0},{3,1,0,2},{0,0,0,0},{3,2,0,1},{3,2,1,0}
};

// 4D simplex noise
stock Float:noise4D(Float:x, Float:y, Float:z, Float:w)
{
    new Float:n0, Float:n1, Float:n2, Float:n3, Float:n4; // Noise contributions from the five corners

    // Skew the (x,y,z,w) space to determine which cell of 24 simplices we're in
    new Float:s = (x + y + z + w) * F4; // Factor for 4D skewing
    new Float:xs = x + s;
    new Float:ys = y + s;
    new Float:zs = z + s;
    new Float:ws = w + s;
    new i = FASTFLOOR(xs);
    new j = FASTFLOOR(ys);
    new k = FASTFLOOR(zs);
    new l = FASTFLOOR(ws);

    new Float:t = (i + j + k + l) * G4; // Factor for 4D unskewing
    new Float:X0 = i - t; // Unskew the cell origin back to (x,y,z,w) space
    new Float:Y0 = j - t;
    new Float:Z0 = k - t;
    new Float:W0 = l - t;

    new Float:x0 = x - X0;  // The x,y,z,w distances from the cell origin
    new Float:y0 = y - Y0;
    new Float:z0 = z - Z0;
    new Float:w0 = w - W0;

    // For the 4D case, the simplex is a 4D shape I won't even try to describe.
    // To find out which of the 24 possible simplices we're in, we need to
    // determine the magnitude ordering of x0, y0, z0 and w0.
    // The method below is a good way of finding the ordering of x,y,z,w and
    // then find the correct traversal order for the simplex weíre in.
    // First, six pair - wise comparisons are performed between each possible pair
    // of the four coordinates, and the results are used to add up binary bits
    // for an integer index.
    new c1 = (x0 > y0) ? 32 : 0;
    new c2 = (x0 > z0) ? 16 : 0;
    new c3 = (y0 > z0) ? 8 : 0;
    new c4 = (x0 > w0) ? 4 : 0;
    new c5 = (y0 > w0) ? 2 : 0;
    new c6 = (z0 > w0) ? 1 : 0;
    new c = c1 + c2 + c3 + c4 + c5 + c6;

    new i1, j1, k1, l1; // The integer offsets for the second simplex corner
    new i2, j2, k2, l2; // The integer offsets for the third simplex corner
    new i3, j3, k3, l3; // The integer offsets for the fourth simplex corner

    // sSimplexLut[c] is a 4 - vector with the numbers 0, 1, 2 and 3 in some order.
    // Many values of c will never occur, since e.g. x > y > z > w makes x < z, y < w and x < w
    // impossible. Only the 24 indices which have non - zero entries make any sense.
    // We use a thresholding to set the coordinates in turn from the largest magnitude.
    // The number 3 in the "simplex" array is at the position of the largest coordinate.
    i1 = sSimplexLut[c][0]>= 3 ? 1 : 0;
    j1 = sSimplexLut[c][1]>= 3 ? 1 : 0;
    k1 = sSimplexLut[c][2]>= 3 ? 1 : 0;
    l1 = sSimplexLut[c][3]>= 3 ? 1 : 0;
    // The number 2 in the "simplex" array is at the second largest coordinate.
    i2 = sSimplexLut[c][0]>= 2 ? 1 : 0;
    j2 = sSimplexLut[c][1]>= 2 ? 1 : 0;
    k2 = sSimplexLut[c][2]>= 2 ? 1 : 0;
    l2 = sSimplexLut[c][3]>= 2 ? 1 : 0;
    // The number 1 in the "simplex" array is at the second smallest coordinate.
    i3 = sSimplexLut[c][0]>= 1 ? 1 : 0;
    j3 = sSimplexLut[c][1]>= 1 ? 1 : 0;
    k3 = sSimplexLut[c][2]>= 1 ? 1 : 0;
    l3 = sSimplexLut[c][3]>= 1 ? 1 : 0;
    // The fifth corner has all coordinate offsets = 1, so no need to look that up.

    new Float:x1 = x0 - i1 + G4; // Offsets for second corner in (x,y,z,w) coords
    new Float:y1 = y0 - j1 + G4;
    new Float:z1 = z0 - k1 + G4;
    new Float:w1 = w0 - l1 + G4;
    new Float:x2 = x0 - i2 + 2.0 *G4; // Offsets for third corner in (x,y,z,w) coords
    new Float:y2 = y0 - j2 + 2.0 *G4;
    new Float:z2 = z0 - k2 + 2.0 *G4;
    new Float:w2 = w0 - l2 + 2.0 *G4;
    new Float:x3 = x0 - i3 + 3.0 *G4; // Offsets for fourth corner in (x,y,z,w) coords
    new Float:y3 = y0 - j3 + 3.0 *G4;
    new Float:z3 = z0 - k3 + 3.0 *G4;
    new Float:w3 = w0 - l3 + 3.0 *G4;
    new Float:x4 = x0 - 1.0 + 4.0 *G4; // Offsets for last corner in (x,y,z,w) coords
    new Float:y4 = y0 - 1.0 + 4.0 *G4;
    new Float:z4 = z0 - 1.0 + 4.0 *G4;
    new Float:w4 = w0 - 1.0 + 4.0 *G4;

    // Wrap the integer indices at 256, to avoid indexing perm[] out of bounds
    new ii = i & 0xff;
    new jj = j & 0xff;
    new kk = k & 0xff;
    new ll = l & 0xff;

    // Calculate the contribution from the five corners
    new Float:t0 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0 - w0 * w0;
    if(t0 < 0.0) n0 = 0.0;
    else {
        t0 *= t0;
        n0 = t0 * t0 * grad4D(perm[ii + perm[jj + perm[kk + perm[ll]]]], x0, y0, z0, w0);
    }

    new Float:t1 = 0.6 - x1 * x1 - y1 * y1 - z1 * z1 - w1 * w1;
    if(t1 < 0.0) n1 = 0.0;
    else {
        t1 *= t1;
        n1 = t1 * t1 * grad4D(perm[ii + i1 + perm[jj + j1 + perm[kk + k1 + perm[ll + l1]]]], x1, y1, z1, w1);
    }

    new Float:t2 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2 - w2 * w2;
    if(t2 < 0.0) n2 = 0.0;
    else {
        t2 *= t2;
        n2 = t2 * t2 * grad4D(perm[ii + i2 + perm[jj + j2 + perm[kk + k2 + perm[ll + l2]]]], x2, y2, z2, w2);
    }

    new Float:t3 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3 - w3 * w3;
    if(t3 < 0.0) n3 = 0.0;
    else {
        t3 *= t3;
        n3 = t3 * t3 * grad4D(perm[ii + i3 + perm[jj + j3 + perm[kk + k3 + perm[ll + l3]]]], x3, y3, z3, w3);
    }

    new Float:t4 = 0.6 - x4 * x4 - y4 * y4 - z4 * z4 - w4 * w4;
    if(t4 < 0.0) n4 = 0.0;
    else {
        t4 *= t4;
        n4 = t4 * t4 * grad4D(perm[ii + 1 + perm[jj + 1 + perm[kk + 1 + perm[ll + 1]]]], x4, y4, z4, w4);
    }

    // Sum up and scale the result to cover the range [- 1,1]
    return 27.0 * (n0 + n1 + n2 + n3 + n4); // TODO: The scale factor is preliminary!
}

stock Float:ridgedNoise1D(Float:x)
{
    return 1.0 - floatabs(noise1D(x));
}
stock Float:ridgedNoise2D(Float:x, Float:y)
{
    return 1.0 - floatabs(noise2D(x, y));
}
stock Float:ridgedNoise3D(Float:x, Float:y, Float:z)
{
    return 1.0 - floatabs(noise3D(x, y, z));
}
stock Float:ridgedNoise4D(Float:x, Float:y, Float:z, Float:w)
{
    return 1.0 - floatabs(noise4D(x, y, z, w));
}

stock dnoise1D(Float:x, &Float:rx, &Float:ry)
{
    new i0 = FASTFLOOR(x);
    new i1 = i0 + 1;
    new Float:x0 = x - i0;
    new Float:x1 = x0 - 1.0;

    new Float:gx0, Float:gx1;
    new Float:n0, Float:n1;
    new Float:t20, Float:t40, Float:t21, Float:t41;

    new Float:x20 = x0 * x0;
    new Float:t0 = 1.0 - x20;
    //  if(t0 < 0.0) t0 = 0.0; // Never happens for 1D: x0 <= 1 always
    t20 = t0 * t0;
    t40 = t20 * t20;
    grad1(perm[i0 & 0xff], gx0);
    n0 = t40 * gx0 * x0;

    new Float:x21 = x1 * x1;
    new Float:t1 = 1.0 - x21;
    //  if(t1 < 0.0) t1 = 0.0; // Never happens for 1D: |x1|<= 1 always
    t21 = t1 * t1;
    t41 = t21 * t21;
    grad1(perm[i1 & 0xff], gx1);
    n1 = t41 * gx1 * x1;

    /* Compute derivative according to:
    *  * dnoise_dx = - 8.0 * t20 * t0 * x0 * (gx0 * x0) + t40 * gx0;
    *  * dnoise_dx += - 8.0 * t21 * t1 * x1 * (gx1 * x1) + t41 * gx1;
    */
    new Float:dnoise_dx = t20 * t0 * gx0 * x20;
    dnoise_dx += t21 * t1 * gx1 * x21;
    dnoise_dx *= - 8.0;
    dnoise_dx += t40 * gx0 + t41 * gx1;
    dnoise_dx *= 0.25; /* Scale derivative to match the noise scaling */

    // The maximum value of this noise is 8 *(3 / 4)^4 = 2.53125
    // A factor of 0.395 would scale to fit exactly within [- 1,1], but
    // to better match classic Perlin noise, we scale it down some more.
    #if defined SIMPLEX_DERIVATIVES_RESCALE
        rx = 0.3961965135 * (n0 + n1), ry = dnoise_dx;
    #else
        rx = 0.25 * (n0 + n1), ry = dnoise_dx;
    #endif
}

stock dnoise2D(Float:x, Float:y, &Float:rx, &Float:ry, &Float:rz)
{
    new Float:n0, Float:n1, Float:n2; // Noise contributions from the three corners

    // Skew the input space to determine which simplex cell we're in
    new Float:s = (x + y)*F2; // Hairy factor for 2D
    new Float:xs = x + s;
    new Float:ys = y + s;
    new i = FASTFLOOR(xs);
    new j = FASTFLOOR(ys);

    new Float:t = float(i + j)*G2;
    new Float:X0 = i - t; // Unskew the cell origin back to (x,y) space
    new Float:Y0 = j - t;
    new Float:x0 = x -X0; // The x,y distances from the cell origin
    new Float:y0 = y -Y0;

    // For the 2D case, the simplex shape is an equilateral triangle.
    // Determine which simplex we are in.
    new i1, j1; // Offsets for second (middle) corner of simplex in (i,j) coords
    if(x0 > y0) {i1 = 1; j1 = 0;} // lower triangle, XY order: (0,0)->(1,0)->(1,1)
    else {i1 = 0; j1 = 1;}      // upper triangle, YX order: (0,0)->(0,1)->(1,1)

    // A step of (1,0) in (i,j) means a step of (1 - c,- c) in (x,y), and
    // a step of (0,1) in (i,j) means a step of (- c,1 - c) in (x,y), where
    // c = (3 - sqrt(3))/ 6

    new Float:x1 = x0 - i1 + G2; // Offsets for middle corner in (x,y) unskewed coords
    new Float:y1 = y0 - j1 + G2;
    new Float:x2 = x0 - 1.0 + 2.0 * G2; // Offsets for last corner in (x,y) unskewed coords
    new Float:y2 = y0 - 1.0 + 2.0 * G2;

    // Wrap the integer indices at 256, to avoid indexing perm[] out of bounds
    new ii = i & 0xff;
    new jj = j & 0xff;

    new Float:gx0, Float:gy0, Float:gx1, Float:gy1, Float:gx2, Float:gy2; /* Gradients at simplex corners */

    /* Calculate the contribution from the three corners */
    new Float:t0 = 0.5 - x0 * x0 - y0 * y0;
    new Float:t20, Float:t40;
    if(t0 < 0.0) t40 = t20 = t0 = n0 = gx0 = gy0 = 0.0; /* No influence */
    else {
        grad2(perm[ii + perm[jj]], gx0, gy0);
        t20 = t0 * t0;
        t40 = t20 * t20;
        n0 = t40 * (gx0 * x0 + gy0 * y0);
    }

    new Float:t1 = 0.5 - x1 * x1 - y1 * y1;
    new Float:t21, Float:t41;
    if(t1 < 0.0) t21 = t41 = t1 = n1 = gx1 = gy1 = 0.0; /* No influence */
    else {
        grad2(perm[ii + i1 + perm[jj + j1]], gx1, gy1);
        t21 = t1 * t1;
        t41 = t21 * t21;
        n1 = t41 * (gx1 * x1 + gy1 * y1);
    }

    new Float:t2 = 0.5 - x2 * x2 - y2 * y2;
    new Float:t22, Float:t42;
    if(t2 < 0.0) t42 = t22 = t2 = n2 = gx2 = gy2 = 0.0; /* No influence */
    else {
        grad2(perm[ii + 1 + perm[jj + 1]], gx2, gy2);
        t22 = t2 * t2;
        t42 = t22 * t22;
        n2 = t42 * (gx2 * x2 + gy2 * y2);
    }

    /* Compute derivative, if requested by supplying non - null pointers
    * for the last two arguments */
    /*  A straight, unoptimised calculation would be like:
    *    * dnoise_dx = - 8.0 * t20 * t0 * x0 * (gx0 * x0 + gy0 * y0) + t40 * gx0;
    *    * dnoise_dy = - 8.0 * t20 * t0 * y0 * (gx0 * x0 + gy0 * y0) + t40 * gy0;
    *    * dnoise_dx += - 8.0 * t21 * t1 * x1 * (gx1 * x1 + gy1 * y1) + t41 * gx1;
    *    * dnoise_dy += - 8.0 * t21 * t1 * y1 * (gx1 * x1 + gy1 * y1) + t41 * gy1;
    *    * dnoise_dx += - 8.0 * t22 * t2 * x2 * (gx2 * x2 + gy2 * y2) + t42 * gx2;
    *    * dnoise_dy += - 8.0 * t22 * t2 * y2 * (gx2 * x2 + gy2 * y2) + t42 * gy2;
    */
    new Float:temp0 = t20 * t0 * (gx0 * x0 + gy0 * y0);
    new Float:dnoise_dx = temp0 * x0;
    new Float:dnoise_dy = temp0 * y0;
    new Float:temp1 = t21 * t1 * (gx1 * x1 + gy1 * y1);
    dnoise_dx += temp1 * x1;
    dnoise_dy += temp1 * y1;
    new Float:temp2 = t22 * t2 * (gx2 * x2 + gy2 * y2);
    dnoise_dx += temp2 * x2;
    dnoise_dy += temp2 * y2;
    dnoise_dx *= - 8.0;
    dnoise_dy *= - 8.0;
    dnoise_dx += t40 * gx0 + t41 * gx1 + t42 * gx2;
    dnoise_dy += t40 * gy0 + t41 * gy1 + t42 * gy2;
    dnoise_dx *= 40.0; /* Scale derivative to match the noise scaling */
    dnoise_dy *= 40.0;

    // Add contributions from each corner to get the final noise value.
    // The result is scaled to return values in the interval [- 1,1].
    #if defined SIMPLEX_DERIVATIVES_RESCALE
        rx = 70.175438596 * (n0 + n1 + n2); // TODO: The scale factor is preliminary!
        ry = dnoise_dx;
        rz = dnoise_dy;
    #else
        rx = 40.0 * (n0 + n1 + n2), ry = dnoise_dx, rz = dnoise_dy; // TODO: The scale factor is preliminary!
    #endif
}

stock dnoise3D(Float:x, Float:y, Float:z, &Float:rx, &Float:ry, &Float:rz, &Float:rw)
{
    new Float:n0, Float:n1, Float:n2, Float:n3; /* Noise contributions from the four simplex corners */
    new Float:rnoise;          /* Return value */
    new Float:gx0, Float:gy0, Float:gz0, Float:gx1, Float:gy1, Float:gz1; /* Gradients at simplex corners */
    new Float:gx2, Float:gy2, Float:gz2, Float:gx3, Float:gy3, Float:gz3;

    /* Skew the input space to determine which simplex cell we're in */
    new Float:s = (x + y + z)*F3; /* Very nice and simple skew factor for 3D */
    new Float:xs = x + s;
    new Float:ys = y + s;
    new Float:zs = z + s;
    new i = FASTFLOOR(xs);
    new j = FASTFLOOR(ys);
    new k = FASTFLOOR(zs);

    new Float:t = float(i + j + k)*G3;
    new Float:X0 = i - t; /* Unskew the cell origin back to (x,y,z) space */
    new Float:Y0 = j - t;
    new Float:Z0 = k - t;
    new Float:x0 = x -X0; /* The x,y,z distances from the cell origin */
    new Float:y0 = y -Y0;
    new Float:z0 = z -Z0;

    /* For the 3D case, the simplex shape is a slightly irregular tetrahedron.
    * Determine which simplex we are in. */
    new i1, j1, k1; /* Offsets for second corner of simplex in (i,j,k) coords */
    new i2, j2, k2; /* Offsets for third corner of simplex in (i,j,k) coords */

    /* TODO: This code would benefit from a backport from the GLSL version! */
    if(x0 >= y0) {
        if(y0 >= z0) { i1 = 1; j1 = 0; k1 = 0; i2 = 1; j2 = 1; k2 = 0; } /* X Y Z order */
        else if(x0 >= z0) { i1 = 1; j1 = 0; k1 = 0; i2 = 1; j2 = 0; k2 = 1; } /* X Z Y order */
        else { i1 = 0; j1 = 0; k1 = 1; i2 = 1; j2 = 0; k2 = 1; } /* Z X Y order */
    }
    else { // x0 < y0
        if(y0 < z0) { i1 = 0; j1 = 0; k1 = 1; i2 = 0; j2 = 1; k2 = 1; } /* Z Y X order */
        else if(x0 < z0) { i1 = 0; j1 = 1; k1 = 0; i2 = 0; j2 = 1; k2 = 1; } /* Y Z X order */
        else { i1 = 0; j1 = 1; k1 = 0; i2 = 1; j2 = 1; k2 = 0; } /* Y X Z order */
    }

    /* A step of (1,0,0) in (i,j,k) means a step of (1 - c,- c,- c) in (x,y,z),
    * a step of (0,1,0) in (i,j,k) means a step of (- c,1 - c,- c) in (x,y,z), and
    * a step of (0,0,1) in (i,j,k) means a step of (- c,- c,1 - c) in (x,y,z), where
    * c = 1 / 6.   */

    new Float:x1 = x0 - i1 + G3; /* Offsets for second corner in (x,y,z) coords */
    new Float:y1 = y0 - j1 + G3;
    new Float:z1 = z0 - k1 + G3;
    new Float:x2 = x0 - i2 + 2.0 * G3; /* Offsets for third corner in (x,y,z) coords */
    new Float:y2 = y0 - j2 + 2.0 * G3;
    new Float:z2 = z0 - k2 + 2.0 * G3;
    new Float:x3 = x0 - 1.0 + 3.0 * G3; /* Offsets for last corner in (x,y,z) coords */
    new Float:y3 = y0 - 1.0 + 3.0 * G3;
    new Float:z3 = z0 - 1.0 + 3.0 * G3;

    /* Wrap the integer indices at 256, to avoid indexing perm[] out of bounds */
    new ii = i & 0xff;
    new jj = j & 0xff;
    new kk = k & 0xff;

    /* Calculate the contribution from the four corners */
    new Float:t0 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0;
    new Float:t20, Float:t40;
    if(t0 < 0.0) n0 = t0 = t20 = t40 = gx0 = gy0 = gz0 = 0.0;
    else {
        grad3(perm[ii + perm[jj + perm[kk]]], gx0, gy0, gz0);
        t20 = t0 * t0;
        t40 = t20 * t20;
        n0 = t40 * (gx0 * x0 + gy0 * y0 + gz0 * z0);
    }

    new Float:t1 = 0.6 - x1 * x1 - y1 * y1 - z1 * z1;
    new Float:t21, Float:t41;
    if(t1 < 0.0) n1 = t1 = t21 = t41 = gx1 = gy1 = gz1 = 0.0;
    else {
        grad3(perm[ii + i1 + perm[jj + j1 + perm[kk + k1]]], gx1, gy1, gz1);
        t21 = t1 * t1;
        t41 = t21 * t21;
        n1 = t41 * (gx1 * x1 + gy1 * y1 + gz1 * z1);
    }

    new Float:t2 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2;
    new Float:t22, Float:t42;
    if(t2 < 0.0) n2 = t2 = t22 = t42 = gx2 = gy2 = gz2 = 0.0;
    else {
        grad3(perm[ii + i2 + perm[jj + j2 + perm[kk + k2]]], gx2, gy2, gz2);
        t22 = t2 * t2;
        t42 = t22 * t22;
        n2 = t42 * (gx2 * x2 + gy2 * y2 + gz2 * z2);
    }

    new Float:t3 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3;
    new Float:t23, Float:t43;
    if(t3 < 0.0) n3 = t3 = t23 = t43 = gx3 = gy3 = gz3 = 0.0;
    else {
        grad3(perm[ii + 1 + perm[jj + 1 + perm[kk + 1]]], gx3, gy3, gz3);
        t23 = t3 * t3;
        t43 = t23 * t23;
        n3 = t43 * (gx3 * x3 + gy3 * y3 + gz3 * z3);
    }

    /*  Add contributions from each corner to get the final rnoise value.
    * The result is scaled to return values in the range [- 1,1] */
    #if defined SIMPLEX_DERIVATIVES_RESCALE
        rnoise = 34.525277436 * (n0 + n1 + n2 + n3);
    #else
        rnoise = 28.0 * (n0 + n1 + n2 + n3);
    #endif

    /* Compute derivative, if requested by supplying non - null pointers
    * for the last three arguments */
    /*  A straight, unoptimised calculation would be like:
    *     * dnoise_dx = - 8.0 * t20 * t0 * x0 * dot(gx0, gy0, gz0, x0, y0, z0) + t40 * gx0;
    *    * dnoise_dy = - 8.0 * t20 * t0 * y0 * dot(gx0, gy0, gz0, x0, y0, z0) + t40 * gy0;
    *    * dnoise_dz = - 8.0 * t20 * t0 * z0 * dot(gx0, gy0, gz0, x0, y0, z0) + t40 * gz0;
    *    * dnoise_dx += - 8.0 * t21 * t1 * x1 * dot(gx1, gy1, gz1, x1, y1, z1) + t41 * gx1;
    *    * dnoise_dy += - 8.0 * t21 * t1 * y1 * dot(gx1, gy1, gz1, x1, y1, z1) + t41 * gy1;
    *    * dnoise_dz += - 8.0 * t21 * t1 * z1 * dot(gx1, gy1, gz1, x1, y1, z1) + t41 * gz1;
    *    * dnoise_dx += - 8.0 * t22 * t2 * x2 * dot(gx2, gy2, gz2, x2, y2, z2) + t42 * gx2;
    *    * dnoise_dy += - 8.0 * t22 * t2 * y2 * dot(gx2, gy2, gz2, x2, y2, z2) + t42 * gy2;
    *    * dnoise_dz += - 8.0 * t22 * t2 * z2 * dot(gx2, gy2, gz2, x2, y2, z2) + t42 * gz2;
    *    * dnoise_dx += - 8.0 * t23 * t3 * x3 * dot(gx3, gy3, gz3, x3, y3, z3) + t43 * gx3;
    *    * dnoise_dy += - 8.0 * t23 * t3 * y3 * dot(gx3, gy3, gz3, x3, y3, z3) + t43 * gy3;
    *    * dnoise_dz += - 8.0 * t23 * t3 * z3 * dot(gx3, gy3, gz3, x3, y3, z3) + t43 * gz3;
    */
    new Float:temp0 = t20 * t0 * (gx0 * x0 + gy0 * y0 + gz0 * z0);
    new Float:dnoise_dx = temp0 * x0;
    new Float:dnoise_dy = temp0 * y0;
    new Float:dnoise_dz = temp0 * z0;
    new Float:temp1 = t21 * t1 * (gx1 * x1 + gy1 * y1 + gz1 * z1);
    dnoise_dx += temp1 * x1;
    dnoise_dy += temp1 * y1;
    dnoise_dz += temp1 * z1;
    new Float:temp2 = t22 * t2 * (gx2 * x2 + gy2 * y2 + gz2 * z2);
    dnoise_dx += temp2 * x2;
    dnoise_dy += temp2 * y2;
    dnoise_dz += temp2 * z2;
    new Float:temp3 = t23 * t3 * (gx3 * x3 + gy3 * y3 + gz3 * z3);
    dnoise_dx += temp3 * x3;
    dnoise_dy += temp3 * y3;
    dnoise_dz += temp3 * z3;
    dnoise_dx *= - 8.0;
    dnoise_dy *= - 8.0;
    dnoise_dz *= - 8.0;
    dnoise_dx += t40 * gx0 + t41 * gx1 + t42 * gx2 + t43 * gx3;
    dnoise_dy += t40 * gy0 + t41 * gy1 + t42 * gy2 + t43 * gy3;
    dnoise_dz += t40 * gz0 + t41 * gz1 + t42 * gz2 + t43 * gz3;
    dnoise_dx *= 28.0; /* Scale derivative to match the rnoise scaling */
    dnoise_dy *= 28.0;
    dnoise_dz *= 28.0;

    rx = rnoise, ry = dnoise_dx, rz = dnoise_dy, rw = dnoise_dz;
}

/*
vec5 dnoise(const vec4 &v)
{
Float:n0, n1, n2, n3, n4; // Noise contributions from the five corners
Float:noise; // Return value
Float:gx0, gy0, gz0, gw0, gx1, gy1, gz1, gw1; // Gradients at simplex corners
Float:gx2, gy2, gz2, gw2, gx3, gy3, gz3, gw3, gx4, gy4, gz4, gw4;
Float:t20, t21, t22, t23, t24;
Float:t40, t41, t42, t43, t44;

// Skew the (x,y,z,w) space to determine which cell of 24 simplices we're in
Float:s = (x + y + z + w) * F4; // Factor for 4D skewing
Float:xs = x + s;
Float:ys = y + s;
Float:zs = z + s;
Float:ws = w + s;
int i = FASTFLOOR(xs);
int j = FASTFLOOR(ys);
int k = FASTFLOOR(zs);
int l = FASTFLOOR(ws);

Float:t = (i + j + k + l) * G4; // Factor for 4D unskewing
Float:X0 = i - t; // Unskew the cell origin back to (x,y,z,w) space
Float:Y0 = j - t;
Float:Z0 = k - t;
Float:W0 = l - t;

Float:x0 = x - X0;  // The x,y,z,w distances from the cell origin
Float:y0 = y - Y0;
Float:z0 = z - Z0;
Float:w0 = w - W0;

// For the 4D case, the simplex is a 4D shape I won't even try to describe.
// To find out which of the 24 possible simplices we're in, we need to
// determine the magnitude ordering of x0, y0, z0 and w0.
// The method below is a reasonable way of finding the ordering of x,y,z,w
// and then find the correct traversal order for the simplex weíre in.
// First, six pair - wise comparisons are performed between each possible pair
// of the four coordinates, and then the results are used to add up binary
// bits for an integer index into a precomputed lookup table, sSimplexLut[].
int c1 = (x0 > y0) ? 32 : 0;
int c2 = (x0 > z0) ? 16 : 0;
int c3 = (y0 > z0) ? 8 : 0;
int c4 = (x0 > w0) ? 4 : 0;
int c5 = (y0 > w0) ? 2 : 0;
int c6 = (z0 > w0) ? 1 : 0;
int c = c1 | c2 | c3 | c4 | c5 | c6; // '|' is mostly faster than '+'

int i1, j1, k1, l1; // The integer offsets for the second simplex corner
int i2, j2, k2, l2; // The integer offsets for the third simplex corner
int i3, j3, k3, l3; // The integer offsets for the fourth simplex corner

// sSimplexLut[c] is a 4 - vector with the numbers 0, 1, 2 and 3 in some order.
// Many values of c will never occur, since e.g. x > y > z > w makes x < z, y < w and x < w
// impossible. Only the 24 indices which have non - zero entries make any sense.
// We use a thresholding to set the coordinates in turn from the largest magnitude.
// The number 3 in the "simplex" array is at the position of the largest coordinate.
i1 = sSimplexLut[c][0]>= 3 ? 1 : 0;
j1 = sSimplexLut[c][1]>= 3 ? 1 : 0;
k1 = sSimplexLut[c][2]>= 3 ? 1 : 0;
l1 = sSimplexLut[c][3]>= 3 ? 1 : 0;
// The number 2 in the "simplex" array is at the second largest coordinate.
i2 = sSimplexLut[c][0]>= 2 ? 1 : 0;
j2 = sSimplexLut[c][1]>= 2 ? 1 : 0;
k2 = sSimplexLut[c][2]>= 2 ? 1 : 0;
l2 = sSimplexLut[c][3]>= 2 ? 1 : 0;
// The number 1 in the "simplex" array is at the second smallest coordinate.
i3 = sSimplexLut[c][0]>= 1 ? 1 : 0;
j3 = sSimplexLut[c][1]>= 1 ? 1 : 0;
k3 = sSimplexLut[c][2]>= 1 ? 1 : 0;
l3 = sSimplexLut[c][3]>= 1 ? 1 : 0;
// The fifth corner has all coordinate offsets = 1, so no need to look that up.

Float:x1 = x0 - i1 + G4; // Offsets for second corner in (x,y,z,w) coords
Float:y1 = y0 - j1 + G4;
Float:z1 = z0 - k1 + G4;
Float:w1 = w0 - l1 + G4;
Float:x2 = x0 - i2 + 2.0 * G4; // Offsets for third corner in (x,y,z,w) coords
Float:y2 = y0 - j2 + 2.0 * G4;
Float:z2 = z0 - k2 + 2.0 * G4;
Float:w2 = w0 - l2 + 2.0 * G4;
Float:x3 = x0 - i3 + 3.0 * G4; // Offsets for fourth corner in (x,y,z,w) coords
Float:y3 = y0 - j3 + 3.0 * G4;
Float:z3 = z0 - k3 + 3.0 * G4;
Float:w3 = w0 - l3 + 3.0 * G4;
Float:x4 = x0 - 1.0 + 4.0 * G4; // Offsets for last corner in (x,y,z,w) coords
Float:y4 = y0 - 1.0 + 4.0 * G4;
Float:z4 = z0 - 1.0 + 4.0 * G4;
Float:w4 = w0 - 1.0 + 4.0 * G4;

// Wrap the integer indices at 256, to avoid indexing perm[] out of bounds
int ii = i & 0xff;
int jj = j & 0xff;
int kk = k & 0xff;
int ll = l & 0xff;

// Calculate the contribution from the five corners
Float:t0 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0 - w0 * w0;
if(t0 < 0.0) n0 = t0 = t20 = t40 = gx0 = gy0 = gz0 = gw0 = 0.0;
else {
t20 = t0 * t0;
t40 = t20 * t20;
grad4(perm[ii + perm[jj + perm[kk + perm[ll]]]], &gx0, &gy0, &gz0, &gw0);
n0 = t40 * (gx0 * x0 + gy0 * y0 + gz0 * z0 + gw0 * w0);
}

Float:t1 = 0.6 - x1 * x1 - y1 * y1 - z1 * z1 - w1 * w1;
if(t1 < 0.0) n1 = t1 = t21 = t41 = gx1 = gy1 = gz1 = gw1 = 0.0;
else {
t21 = t1 * t1;
t41 = t21 * t21;
grad4(perm[ii + i1 + perm[jj + j1 + perm[kk + k1 + perm[ll + l1]]]], &gx1, &gy1, &gz1, &gw1);
n1 = t41 * (gx1 * x1 + gy1 * y1 + gz1 * z1 + gw1 * w1);
}

Float:t2 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2 - w2 * w2;
if(t2 < 0.0) n2 = t2 = t22 = t42 = gx2 = gy2 = gz2 = gw2 = 0.0;
else {
t22 = t2 * t2;
t42 = t22 * t22;
grad4(perm[ii + i2 + perm[jj + j2 + perm[kk + k2 + perm[ll + l2]]]], &gx2, &gy2, &gz2, &gw2);
n2 = t42 * (gx2 * x2 + gy2 * y2 + gz2 * z2 + gw2 * w2);
}

Float:t3 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3 - w3 * w3;
if(t3 < 0.0) n3 = t3 = t23 = t43 = gx3 = gy3 = gz3 = gw3 = 0.0;
else {
t23 = t3 * t3;
t43 = t23 * t23;
grad4(perm[ii + i3 + perm[jj + j3 + perm[kk + k3 + perm[ll + l3]]]], &gx3, &gy3, &gz3, &gw3);
n3 = t43 * (gx3 * x3 + gy3 * y3 + gz3 * z3 + gw3 * w3);
}

Float:t4 = 0.6 - x4 * x4 - y4 * y4 - z4 * z4 - w4 * w4;
if(t4 < 0.0) n4 = t4 = t24 = t44 = gx4 = gy4 = gz4 = gw4 = 0.0;
else {
t24 = t4 * t4;
t44 = t24 * t24;
grad4(perm[ii + 1 + perm[jj + 1 + perm[kk + 1 + perm[ll + 1]]]], &gx4, &gy4, &gz4, &gw4);
n4 = t44 * (gx4 * x4 + gy4 * y4 + gz4 * z4 + gw4 * w4);
}

// Sum up and scale the result to cover the range [- 1,1]
noise = 27.0 * (n0 + n1 + n2 + n3 + n4); // TODO: The scale factor is preliminary!

// Compute derivative, if requested by supplying non - null pointers
// for the last four arguments

//   A straight, unoptimised calculation would be like:
//   * dnoise_dx = - 8.0 * t20 * t0 * x0 * dot(gx0, gy0, gz0, gw0, x0, y0, z0, w0) + t40 * gx0;
//   * dnoise_dy = - 8.0 * t20 * t0 * y0 * dot(gx0, gy0, gz0, gw0, x0, y0, z0, w0) + t40 * gy0;
//   * dnoise_dz = - 8.0 * t20 * t0 * z0 * dot(gx0, gy0, gz0, gw0, x0, y0, z0, w0) + t40 * gz0;
//   * dnoise_dw = - 8.0 * t20 * t0 * w0 * dot(gx0, gy0, gz0, gw0, x0, y0, z0, w0) + t40 * gw0;
//   * dnoise_dx += - 8.0 * t21 * t1 * x1 * dot(gx1, gy1, gz1, gw1, x1, y1, z1, w1) + t41 * gx1;
//   * dnoise_dy += - 8.0 * t21 * t1 * y1 * dot(gx1, gy1, gz1, gw1, x1, y1, z1, w1) + t41 * gy1;
//   * dnoise_dz += - 8.0 * t21 * t1 * z1 * dot(gx1, gy1, gz1, gw1, x1, y1, z1, w1) + t41 * gz1;
//   * dnoise_dw = - 8.0 * t21 * t1 * w1 * dot(gx1, gy1, gz1, gw1, x1, y1, z1, w1) + t41 * gw1;
//   * dnoise_dx += - 8.0 * t22 * t2 * x2 * dot(gx2, gy2, gz2, gw2, x2, y2, z2, w2) + t42 * gx2;
//   * dnoise_dy += - 8.0 * t22 * t2 * y2 * dot(gx2, gy2, gz2, gw2, x2, y2, z2, w2) + t42 * gy2;
//   * dnoise_dz += - 8.0 * t22 * t2 * z2 * dot(gx2, gy2, gz2, gw2, x2, y2, z2, w2) + t42 * gz2;
//   * dnoise_dw += - 8.0 * t22 * t2 * w2 * dot(gx2, gy2, gz2, gw2, x2, y2, z2, w2) + t42 * gw2;
//   * dnoise_dx += - 8.0 * t23 * t3 * x3 * dot(gx3, gy3, gz3, gw3, x3, y3, z3, w3) + t43 * gx3;
//   * dnoise_dy += - 8.0 * t23 * t3 * y3 * dot(gx3, gy3, gz3, gw3, x3, y3, z3, w3) + t43 * gy3;
//   * dnoise_dz += - 8.0 * t23 * t3 * z3 * dot(gx3, gy3, gz3, gw3, x3, y3, z3, w3) + t43 * gz3;
//   * dnoise_dw += - 8.0 * t23 * t3 * w3 * dot(gx3, gy3, gz3, gw3, x3, y3, z3, w3) + t43 * gw3;
//   * dnoise_dx += - 8.0 * t24 * t4 * x4 * dot(gx4, gy4, gz4, gw4, x4, y4, z4, w4) + t44 * gx4;
//   * dnoise_dy += - 8.0 * t24 * t4 * y4 * dot(gx4, gy4, gz4, gw4, x4, y4, z4, w4) + t44 * gy4;
//   * dnoise_dz += - 8.0 * t24 * t4 * z4 * dot(gx4, gy4, gz4, gw4, x4, y4, z4, w4) + t44 * gz4;
//   * dnoise_dw += - 8.0 * t24 * t4 * w4 * dot(gx4, gy4, gz4, gw4, x4, y4, z4, w4) + t44 * gw4;
//
Float:temp0 = t20 * t0 * (gx0 * x0 + gy0 * y0 + gz0 * z0 + gw0 * w0);
Float:dnoise_dx = temp0 * x0;
Float:dnoise_dy = temp0 * y0;
Float:dnoise_dz = temp0 * z0;
Float:dnoise_dw = temp0 * w0;
Float:temp1 = t21 * t1 * (gx1 * x1 + gy1 * y1 + gz1 * z1 + gw1 * w1);
dnoise_dx += temp1 * x1;
dnoise_dy += temp1 * y1;
dnoise_dz += temp1 * z1;
dnoise_dw += temp1 * w1;
Float:temp2 = t22 * t2 * (gx2 * x2 + gy2 * y2 + gz2 * z2 + gw2 * w2);
dnoise_dx += temp2 * x2;
dnoise_dy += temp2 * y2;
dnoise_dz += temp2 * z2;
dnoise_dw += temp2 * w2;
Float:temp3 = t23 * t3 * (gx3 * x3 + gy3 * y3 + gz3 * z3 + gw3 * w3);
dnoise_dx += temp3 * x3;
dnoise_dy += temp3 * y3;
dnoise_dz += temp3 * z3;
dnoise_dw += temp3 * w3;
Float:temp4 = t24 * t4 * (gx4 * x4 + gy4 * y4 + gz4 * z4 + gw4 * w4);
dnoise_dx += temp4 * x4;
dnoise_dy += temp4 * y4;
dnoise_dz += temp4 * z4;
dnoise_dw += temp4 * w4;
dnoise_dx *= - 8.0;
dnoise_dy *= - 8.0;
dnoise_dz *= - 8.0;
dnoise_dw *= - 8.0;
dnoise_dx += t40 * gx0 + t41 * gx1 + t42 * gx2 + t43 * gx3 + t44 * gx4;
dnoise_dy += t40 * gy0 + t41 * gy1 + t42 * gy2 + t43 * gy3 + t44 * gy4;
dnoise_dz += t40 * gz0 + t41 * gz1 + t42 * gz2 + t43 * gz3 + t44 * gz4;
dnoise_dw += t40 * gw0 + t41 * gw1 + t42 * gw2 + t43 * gw3 + t44 * gw4;

dnoise_dx *= 28.0; // Scale derivative to match the noise scaling
dnoise_dy *= 28.0;
dnoise_dz *= 28.0;
dnoise_dw *= 28.0;

return { noise, dnoise_dx, dnoise_dy, dnoise_dz, dnoise_dw };
}
*/

#define floatfloor(%0) (floatround(%0,floatround_floor))
#define floatfract(%0) (%0 - floatfloor(%0))
#define dot(%0,%1) ((%0x * %1x) + (%0y * %1y))
#define min(%0,%1) (%0<%1?%0:%1)

stock Float:worleyNoise2D(Float:x, Float:y)
{
    new Float:px = floatfloor(x), Float:py = floatfloor(y);
    new Float:fx = floatfract(x), Float:fy = floatfract(y);

    new Float:res = 8.0;
    for(new j =- 1; j <= 1; j ++) {
        for(new i =- 1; i <= 1; i ++) {
            new Float:bx = float(i), Float:by = float(j);
            new Float:rx = bx - fx + (noise1D(px + bx) * 0.5 + 0.5);
            new Float:ry = by - fy + (noise1D(py + by) * 0.5 + 0.5);
            new Float:d = dot(r, r);
            res = min(res, d);
        }
    }
    return floatsqroot(res);
}

#undef dot
#define dot(%0,%1) ((%0x * %1x) + (%0y * %1y) + (%0z * %1z))

stock Float:worleyNoise3D(Float:x, Float:y, Float:z)
{
    new Float:px = floatfloor(x), Float:py = floatfloor(y), Float:pz = floatfloor(z);
    new Float:fx = floatfract(x), Float:fy = floatfract(y), Float:fz = floatfract(z);

    new Float:res = 8.0;
    for(new k =- 1; k <= 1; k ++) {
        for(new j =- 1; j <= 1; j ++) {
            for(new i =- 1; i <= 1; i ++) {
                new Float:bx = i, Float:by = j, Float:bz = k;
                new Float:rx = bx - fx + (noise1D(px + bx) * 0.5 + 0.5);
                new Float:ry = by - fy + (noise1D(py + by) * 0.5 + 0.5);
                new Float:rz = bz - fz + (noise1D(pz + bz) * 0.5 + 0.5);
                new Float:d = dot(r, r);
                res = min(res, d);
            }
        }
    }
    return floatsqroot(res);
}

#undef dot
#define dot(%0,%1) ((%0x * %1x) + (%0y * %1y))

#define log(%0) floatlog(%0,10.0)

#define exp(%0) (floatpower(2.71828, %0))

stock Float:worleyNoise2D_F(Float:x, Float:y, Float:falloff)
{
    new Float:px = floatfloor(x), Float:py = floatfloor(y);
    new Float:fx = floatfract(x), Float:fy = floatfract(y);

    new Float:res = 0.0;
    for(new j =- 1; j <= 1; j ++) {
        for(new i =- 1; i <= 1; i ++) {
            new Float:bx = float(i), Float:by = float(j);
            new Float:rx = bx - fx + (noise1D(px + bx) * 0.5 + 0.5);
            new Float:ry = by - fy + (noise1D(py + by) * 0.5 + 0.5);
            new Float:d = VectorSize(rx, ry, 0.0);
            res += exp(- falloff * d);
        }
    }
    return -(1.0 / falloff) * log(res);
}

#undef dot
#define dot(%0,%1) ((%0x * %1x) + (%0y * %1y) + (%0z * %1z))

stock Float:worleyNoise3D_F(Float:x, Float:y, Float:z, Float:falloff)
{
    new Float:px = floatfloor(x), Float:py = floatfloor(y), Float:pz = floatfloor(z);
    new Float:fx = floatfract(x), Float:fy = floatfract(y), Float:fz = floatfract(z);

    new Float:res = 0.0;
    for(new k =- 1; k <= 1; k ++) {
        for(new j =- 1; j <= 1; j ++) {
            for(new i =- 1; i <= 1; i ++) {
                new Float:bx = i, Float:by = j, Float:bz = k;
                new Float:rx = bx - fx + (noise1D(px + bx) * 0.5 + 0.5);
                new Float:ry = by - fy + (noise1D(py + by) * 0.5 + 0.5);
                new Float:rz = bz - fz + (noise1D(pz + bz) * 0.5 + 0.5);
                new Float:d = VectorSize(rx, ry, rz);
                res += exp(- falloff * d);
            }
        }
    }
    return -(1.0 / falloff) * log(res);
}


#undef FASTFLOOR
#undef F2
#undef G2
#undef F3
#undef G3
#undef F4
#undef G4
#undef floatfloor
#undef floatfract
#undef dot
#undef min
#undef log
#undef exp

#endinput

Float:flowNoise(const vec2 &v, Float:angle)
{
Float:n0, n1, n2; /* Noise contributions from the three simplex corners */
Float:gx0, gy0, gx1, gy1, gx2, gy2; /* Gradients at simplex corners */
Float:sin_t, cos_t; /* Sine and cosine for the gradient rotation angle */
sin_t = sin(angle);
cos_t = cos(angle);

/* Skew the input space to determine which simplex cell we're in */
Float:s = (x + y) * F2; /* Hairy factor for 2D */
Float:xs = x + s;
Float:ys = y + s;
int i = FASTFLOOR(xs);
int j = FASTFLOOR(ys);

Float:t = (float) (i + j) * G2;
Float:X0 = i - t; /* Unskew the cell origin back to (x,y) space */
Float:Y0 = j - t;
Float:x0 = x - X0; /* The x,y distances from the cell origin */
Float:y0 = y - Y0;

/* For the 2D case, the simplex shape is an equilateral triangle.
* Determine which simplex we are in. */
int i1, j1; /* Offsets for second (middle) corner of simplex in (i,j) coords */
if(x0 > y0) { i1 = 1; j1 = 0; } /* lower triangle, XY order: (0,0)->(1,0)->(1,1) */
else { i1 = 0; j1 = 1; }      /* upper triangle, YX order: (0,0)->(0,1)->(1,1) */

/* A step of (1,0) in (i,j) means a step of (1 - c,- c) in (x,y), and
* a step of (0,1) in (i,j) means a step of (- c,1 - c) in (x,y), where
* c = (3 - sqrt(3))/ 6   */
Float:x1 = x0 - i1 + G2; /* Offsets for middle corner in (x,y) unskewed coords */
Float:y1 = y0 - j1 + G2;
Float:x2 = x0 - 1.0 + 2.0 * G2; /* Offsets for last corner in (x,y) unskewed coords */
Float:y2 = y0 - 1.0 + 2.0 * G2;

/* Wrap the integer indices at 256, to avoid indexing perm[] out of bounds */
int ii = i & 0xff;
int jj = j & 0xff;

/* Calculate the contribution from the three corners */
Float:t0 = 0.5 - x0 * x0 - y0 * y0;
Float:t20, t40;
if(t0 < 0.0) t40 = t20 = t0 = n0 = gx0 = gy0 = 0.0; /* No influence */
else {
gradrot2(perm[ii + perm[jj]], sin_t, cos_t, &gx0, &gy0);
t20 = t0 * t0;
t40 = t20 * t20;
n0 = t40 * graddotp2(gx0, gy0, x0, y0);
}

Float:t1 = 0.5 - x1 * x1 - y1 * y1;
Float:t21, t41;
if(t1 < 0.0) t21 = t41 = t1 = n1 = gx1 = gy1 = 0.0; /* No influence */
else {
gradrot2(perm[ii + i1 + perm[jj + j1]], sin_t, cos_t, &gx1, &gy1);
t21 = t1 * t1;
t41 = t21 * t21;
n1 = t41 * graddotp2(gx1, gy1, x1, y1);
}

Float:t2 = 0.5 - x2 * x2 - y2 * y2;
Float:t22, t42;
if(t2 < 0.0) t42 = t22 = t2 = n2 = gx2 = gy2 = 0.0; /* No influence */
else {
gradrot2(perm[ii + 1 + perm[jj + 1]], sin_t, cos_t, &gx2, &gy2);
t22 = t2 * t2;
t42 = t22 * t22;
n2 = t42 * graddotp2(gx2, gy2, x2, y2);
}

/* Add contributions from each corner to get the final noise value.
* The result is scaled to return values in the interval [- 1,1]. */
return 40.0 * (n0 + n1 + n2);
}
Float:flowNoise(const vec3 &v, Float:angle)
{
Float:n0, n1, n2, n3; /* Noise contributions from the four simplex corners */
Float:gx0, gy0, gz0, gx1, gy1, gz1; /* Gradients at simplex corners */
Float:gx2, gy2, gz2, gx3, gy3, gz3;
Float:sin_t, cos_t; /* Sine and cosine for the gradient rotation angle */
sin_t = sin(angle);
cos_t = cos(angle);

/* Skew the input space to determine which simplex cell we're in */
Float:s = (x + y + z)*F3; /* Very nice and simple skew factor for 3D */
Float:xs = x + s;
Float:ys = y + s;
Float:zs = z + s;
int i = FASTFLOOR(xs);
int j = FASTFLOOR(ys);
int k = FASTFLOOR(zs);

Float:t = (float)(i + j + k)*G3;
Float:X0 = i - t; /* Unskew the cell origin back to (x,y,z) space */
Float:Y0 = j - t;
Float:Z0 = k - t;
Float:x0 = x -X0; /* The x,y,z distances from the cell origin */
Float:y0 = y -Y0;
Float:z0 = z -Z0;

/* For the 3D case, the simplex shape is a slightly irregular tetrahedron.
* Determine which simplex we are in. */
int i1, j1, k1; /* Offsets for second corner of simplex in (i,j,k) coords */
int i2, j2, k2; /* Offsets for third corner of simplex in (i,j,k) coords */

/* TODO: This code would benefit from a backport from the GLSL version! */
if(x0 >= y0) {
if(y0 >= z0)
{ i1 = 1; j1 = 0; k1 = 0; i2 = 1; j2 = 1; k2 = 0; } /* X Y Z order */
else if(x0 >= z0) { i1 = 1; j1 = 0; k1 = 0; i2 = 1; j2 = 0; k2 = 1; } /* X Z Y order */
else { i1 = 0; j1 = 0; k1 = 1; i2 = 1; j2 = 0; k2 = 1; } /* Z X Y order */
}
else { // x0 < y0
if(y0 < z0) { i1 = 0; j1 = 0; k1 = 1; i2 = 0; j2 = 1; k2 = 1; } /* Z Y X order */
else if(x0 < z0) { i1 = 0; j1 = 1; k1 = 0; i2 = 0; j2 = 1; k2 = 1; } /* Y Z X order */
else { i1 = 0; j1 = 1; k1 = 0; i2 = 1; j2 = 1; k2 = 0; } /* Y X Z order */
}

/* A step of (1,0,0) in (i,j,k) means a step of (1 - c,- c,- c) in (x,y,z),
* a step of (0,1,0) in (i,j,k) means a step of (- c,1 - c,- c) in (x,y,z), and
* a step of (0,0,1) in (i,j,k) means a step of (- c,- c,1 - c) in (x,y,z), where
* c = 1 / 6.   */

Float:x1 = x0 - i1 + G3; /* Offsets for second corner in (x,y,z) coords */
Float:y1 = y0 - j1 + G3;
Float:z1 = z0 - k1 + G3;
Float:x2 = x0 - i2 + 2.0 * G3; /* Offsets for third corner in (x,y,z) coords */
Float:y2 = y0 - j2 + 2.0 * G3;
Float:z2 = z0 - k2 + 2.0 * G3;
Float:x3 = x0 - 1.0 + 3.0 * G3; /* Offsets for last corner in (x,y,z) coords */
Float:y3 = y0 - 1.0 + 3.0 * G3;
Float:z3 = z0 - 1.0 + 3.0 * G3;

/* Wrap the integer indices at 256, to avoid indexing perm[] out of bounds */
int ii = i & 0xff;
int jj = j & 0xff;
int kk = k & 0xff;

/* Calculate the contribution from the four corners */
Float:t0 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0;
Float:t20, t40;
if(t0 < 0.0) n0 = t0 = t20 = t40 = gx0 = gy0 = gz0 = 0.0;
else {
gradrot3(perm[ii + perm[jj + perm[kk]]], sin_t, cos_t, &gx0, &gy0, &gz0);
t20 = t0 * t0;
t40 = t20 * t20;
n0 = t40 * graddotp3(gx0, gy0, gz0, x0, y0, z0);
}

Float:t1 = 0.6 - x1 * x1 - y1 * y1 - z1 * z1;
Float:t21, t41;
if(t1 < 0.0) n1 = t1 = t21 = t41 = gx1 = gy1 = gz1 = 0.0;
else {
gradrot3(perm[ii + i1 + perm[jj + j1 + perm[kk + k1]]], sin_t, cos_t, &gx1, &gy1, &gz1);
t21 = t1 * t1;
t41 = t21 * t21;
n1 = t41 * graddotp3(gx1, gy1, gz1, x1, y1, z1);
}

Float:t2 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2;
Float:t22, t42;
if(t2 < 0.0) n2 = t2 = t22 = t42 = gx2 = gy2 = gz2 = 0.0;
else {
gradrot3(perm[ii + i2 + perm[jj + j2 + perm[kk + k2]]], sin_t, cos_t, &gx2, &gy2, &gz2);
t22 = t2 * t2;
t42 = t22 * t22;
n2 = t42 * graddotp3(gx2, gy2, gz2, x2, y2, z2);
}

Float:t3 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3;
Float:t23, t43;
if(t3 < 0.0) n3 = t3 = t23 = t43 = gx3 = gy3 = gz3 = 0.0;
else {
gradrot3(perm[ii + 1 + perm[jj + 1 + perm[kk + 1]]], sin_t, cos_t, &gx3, &gy3, &gz3);
t23 = t3 * t3;
t43 = t23 * t23;
n3 = t43 * graddotp3(gx3, gy3, gz3, x3, y3, z3);
}

/*  Add contributions from each corner to get the final noise value.
* The result is scaled to return values in the range [- 1,1] */
return 28.0 * (n0 + n1 + n2 + n3);
}
vec3 dFlowNoise(const vec2 &v, Float:angle)
{

Float:n0, n1, n2; /* Noise contributions from the three simplex corners */
Float:gx0, gy0, gx1, gy1, gx2, gy2; /* Gradients at simplex corners */
Float:sin_t, cos_t; /* Sine and cosine for the gradient rotation angle */
sin_t = sin(angle);
cos_t = cos(angle);

/* Skew the input space to determine which simplex cell we're in */
Float:s = (x + y) * F2; /* Hairy factor for 2D */
Float:xs = x + s;
Float:ys = y + s;
int i = FASTFLOOR(xs);
int j = FASTFLOOR(ys);

Float:t = (float) (i + j) * G2;
Float:X0 = i - t; /* Unskew the cell origin back to (x,y) space */
Float:Y0 = j - t;
Float:x0 = x - X0; /* The x,y distances from the cell origin */
Float:y0 = y - Y0;

/* For the 2D case, the simplex shape is an equilateral triangle.
* Determine which simplex we are in. */
int i1, j1; /* Offsets for second (middle) corner of simplex in (i,j) coords */
if(x0 > y0) { i1 = 1; j1 = 0; } /* lower triangle, XY order: (0,0)->(1,0)->(1,1) */
else { i1 = 0; j1 = 1; }      /* upper triangle, YX order: (0,0)->(0,1)->(1,1) */

/* A step of (1,0) in (i,j) means a step of (1 - c,- c) in (x,y), and
* a step of (0,1) in (i,j) means a step of (- c,1 - c) in (x,y), where
* c = (3 - sqrt(3))/ 6   */
Float:x1 = x0 - i1 + G2; /* Offsets for middle corner in (x,y) unskewed coords */
Float:y1 = y0 - j1 + G2;
Float:x2 = x0 - 1.0 + 2.0 * G2; /* Offsets for last corner in (x,y) unskewed coords */
Float:y2 = y0 - 1.0 + 2.0 * G2;

/* Wrap the integer indices at 256, to avoid indexing perm[] out of bounds */
int ii = i & 0xff;
int jj = j & 0xff;

/* Calculate the contribution from the three corners */
Float:t0 = 0.5 - x0 * x0 - y0 * y0;
Float:t20, t40;
if(t0 < 0.0) t40 = t20 = t0 = n0 = gx0 = gy0 = 0.0; /* No influence */
else {
gradrot2(perm[ii + perm[jj]], sin_t, cos_t, &gx0, &gy0);
t20 = t0 * t0;
t40 = t20 * t20;
n0 = t40 * graddotp2(gx0, gy0, x0, y0);
}

Float:t1 = 0.5 - x1 * x1 - y1 * y1;
Float:t21, t41;
if(t1 < 0.0) t21 = t41 = t1 = n1 = gx1 = gy1 = 0.0; /* No influence */
else {
gradrot2(perm[ii + i1 + perm[jj + j1]], sin_t, cos_t, &gx1, &gy1);
t21 = t1 * t1;
t41 = t21 * t21;
n1 = t41 * graddotp2(gx1, gy1, x1, y1);
}

Float:t2 = 0.5 - x2 * x2 - y2 * y2;
Float:t22, t42;
if(t2 < 0.0) t42 = t22 = t2 = n2 = gx2 = gy2 = 0.0; /* No influence */
else {
gradrot2(perm[ii + 1 + perm[jj + 1]], sin_t, cos_t, &gx2, &gy2);
t22 = t2 * t2;
t42 = t22 * t22;
n2 = t42 * graddotp2(gx2, gy2, x2, y2);
}

/* Add contributions from each corner to get the final noise value.
* The result is scaled to return values in the interval [- 1,1]. */
Float:noise = 40.0 * (n0 + n1 + n2);

/* Compute derivative, if requested by supplying non - null pointers
* for the last two arguments */
Float:dnoise_dx, dnoise_dy;

/*  A straight, unoptimised calculation would be like:
*    * dnoise_dx = - 8.0 * t20 * t0 * x0 * graddotp2(gx0, gy0, x0, y0) + t40 * gx0;
*    * dnoise_dy = - 8.0 * t20 * t0 * y0 * graddotp2(gx0, gy0, x0, y0) + t40 * gy0;
*    * dnoise_dx += - 8.0 * t21 * t1 * x1 * graddotp2(gx1, gy1, x1, y1) + t41 * gx1;
*    * dnoise_dy += - 8.0 * t21 * t1 * y1 * graddotp2(gx1, gy1, x1, y1) + t41 * gy1;
*    * dnoise_dx += - 8.0 * t22 * t2 * x2 * graddotp2(gx2, gy2, x2, y2) + t42 * gx2;
*    * dnoise_dy += - 8.0 * t22 * t2 * y2 * graddotp2(gx2, gy2, x2, y2) + t42 * gy2;
*/
Float:temp0 = t20 * t0 * graddotp2(gx0, gy0, x0, y0);
dnoise_dx = temp0 * x0;
dnoise_dy = temp0 * y0;
Float:temp1 = t21 * t1 * graddotp2(gx1, gy1, x1, y1);
dnoise_dx += temp1 * x1;
dnoise_dy += temp1 * y1;
Float:temp2 = t22 * t2 * graddotp2(gx2, gy2, x2, y2);
dnoise_dx += temp2 * x2;
dnoise_dy += temp2 * y2;
dnoise_dx *= - 8.0;
dnoise_dy *= - 8.0;
/* This corrects a bug in the original implementation */
dnoise_dx += t40 * gx0 + t41 * gx1 + t42 * gx2;
dnoise_dy += t40 * gy0 + t41 * gy1 + t42 * gy2;
dnoise_dx *= 40.0; /* Scale derivative to match the noise scaling */
dnoise_dy *= 40.0;

return vec3(noise, dnoise_dx, dnoise_dy);
}
vec4 dFlowNoise(const vec3 &v, Float:angle)
{
Float:n0, n1, n2, n3; /* Noise contributions from the four simplex corners */
Float:noise;          /* Return value */
Float:gx0, gy0, gz0, gx1, gy1, gz1; /* Gradients at simplex corners */
Float:gx2, gy2, gz2, gx3, gy3, gz3;
Float:sin_t, cos_t; /* Sine and cosine for the gradient rotation angle */
sin_t = sin(angle);
cos_t = cos(angle);

/* Skew the input space to determine which simplex cell we're in */
Float:s = (x + y + z)*F3; /* Very nice and simple skew factor for 3D */
Float:xs = x + s;
Float:ys = y + s;
Float:zs = z + s;
int i = FASTFLOOR(xs);
int j = FASTFLOOR(ys);
int k = FASTFLOOR(zs);

Float:t = (float)(i + j + k)*G3;
Float:X0 = i - t; /* Unskew the cell origin back to (x,y,z) space */
Float:Y0 = j - t;
Float:Z0 = k - t;
Float:x0 = x -X0; /* The x,y,z distances from the cell origin */
Float:y0 = y -Y0;
Float:z0 = z -Z0;

/* For the 3D case, the simplex shape is a slightly irregular tetrahedron.
* Determine which simplex we are in. */
int i1, j1, k1; /* Offsets for second corner of simplex in (i,j,k) coords */
int i2, j2, k2; /* Offsets for third corner of simplex in (i,j,k) coords */

/* TODO: This code would benefit from a backport from the GLSL version! */
if(x0 >= y0) {
if(y0 >= z0)
{ i1 = 1; j1 = 0; k1 = 0; i2 = 1; j2 = 1; k2 = 0; } /* X Y Z order */
else if(x0 >= z0) { i1 = 1; j1 = 0; k1 = 0; i2 = 1; j2 = 0; k2 = 1; } /* X Z Y order */
else { i1 = 0; j1 = 0; k1 = 1; i2 = 1; j2 = 0; k2 = 1; } /* Z X Y order */
}
else { // x0 < y0
if(y0 < z0) { i1 = 0; j1 = 0; k1 = 1; i2 = 0; j2 = 1; k2 = 1; } /* Z Y X order */
else if(x0 < z0) { i1 = 0; j1 = 1; k1 = 0; i2 = 0; j2 = 1; k2 = 1; } /* Y Z X order */
else { i1 = 0; j1 = 1; k1 = 0; i2 = 1; j2 = 1; k2 = 0; } /* Y X Z order */
}

/* A step of (1,0,0) in (i,j,k) means a step of (1 - c,- c,- c) in (x,y,z),
* a step of (0,1,0) in (i,j,k) means a step of (- c,1 - c,- c) in (x,y,z), and
* a step of (0,0,1) in (i,j,k) means a step of (- c,- c,1 - c) in (x,y,z), where
* c = 1 / 6.   */

Float:x1 = x0 - i1 + G3; /* Offsets for second corner in (x,y,z) coords */
Float:y1 = y0 - j1 + G3;
Float:z1 = z0 - k1 + G3;
Float:x2 = x0 - i2 + 2.0 * G3; /* Offsets for third corner in (x,y,z) coords */
Float:y2 = y0 - j2 + 2.0 * G3;
Float:z2 = z0 - k2 + 2.0 * G3;
Float:x3 = x0 - 1.0 + 3.0 * G3; /* Offsets for last corner in (x,y,z) coords */
Float:y3 = y0 - 1.0 + 3.0 * G3;
Float:z3 = z0 - 1.0 + 3.0 * G3;

/* Wrap the integer indices at 256, to avoid indexing perm[] out of bounds */
int ii = i & 0xff;
int jj = j & 0xff;
int kk = k & 0xff;

/* Calculate the contribution from the four corners */
Float:t0 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0;
Float:t20, t40;
if(t0 < 0.0) n0 = t0 = t20 = t40 = gx0 = gy0 = gz0 = 0.0;
else {
gradrot3(perm[ii + perm[jj + perm[kk]]], sin_t, cos_t, &gx0, &gy0, &gz0);
t20 = t0 * t0;
t40 = t20 * t20;
n0 = t40 * graddotp3(gx0, gy0, gz0, x0, y0, z0);
}

Float:t1 = 0.6 - x1 * x1 - y1 * y1 - z1 * z1;
Float:t21, t41;
if(t1 < 0.0) n1 = t1 = t21 = t41 = gx1 = gy1 = gz1 = 0.0;
else {
gradrot3(perm[ii + i1 + perm[jj + j1 + perm[kk + k1]]], sin_t, cos_t, &gx1, &gy1, &gz1);
t21 = t1 * t1;
t41 = t21 * t21;
n1 = t41 * graddotp3(gx1, gy1, gz1, x1, y1, z1);
}

Float:t2 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2;
Float:t22, t42;
if(t2 < 0.0) n2 = t2 = t22 = t42 = gx2 = gy2 = gz2 = 0.0;
else {
gradrot3(perm[ii + i2 + perm[jj + j2 + perm[kk + k2]]], sin_t, cos_t, &gx2, &gy2, &gz2);
t22 = t2 * t2;
t42 = t22 * t22;
n2 = t42 * graddotp3(gx2, gy2, gz2, x2, y2, z2);
}

Float:t3 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3;
Float:t23, t43;
if(t3 < 0.0) n3 = t3 = t23 = t43 = gx3 = gy3 = gz3 = 0.0;
else {
gradrot3(perm[ii + 1 + perm[jj + 1 + perm[kk + 1]]], sin_t, cos_t, &gx3, &gy3, &gz3);
t23 = t3 * t3;
t43 = t23 * t23;
n3 = t43 * graddotp3(gx3, gy3, gz3, x3, y3, z3);
}

/*  Add contributions from each corner to get the final noise value.
* The result is scaled to return values in the range [- 1,1] */
noise = 28.0 * (n0 + n1 + n2 + n3);

/* Compute derivative, if requested by supplying non - null pointers
* for the last three arguments */
Float:dnoise_dx, dnoise_dy, dnoise_dz;

/*  A straight, unoptimised calculation would be like:
*     * dnoise_dx = - 8.0 * t20 * t0 * x0 * graddotp3(gx0, gy0, gz0, x0, y0, z0) + t40 * gx0;
*    * dnoise_dy = - 8.0 * t20 * t0 * y0 * graddotp3(gx0, gy0, gz0, x0, y0, z0) + t40 * gy0;
*    * dnoise_dz = - 8.0 * t20 * t0 * z0 * graddotp3(gx0, gy0, gz0, x0, y0, z0) + t40 * gz0;
*    * dnoise_dx += - 8.0 * t21 * t1 * x1 * graddotp3(gx1, gy1, gz1, x1, y1, z1) + t41 * gx1;
*    * dnoise_dy += - 8.0 * t21 * t1 * y1 * graddotp3(gx1, gy1, gz1, x1, y1, z1) + t41 * gy1;
*    * dnoise_dz += - 8.0 * t21 * t1 * z1 * graddotp3(gx1, gy1, gz1, x1, y1, z1) + t41 * gz1;
*    * dnoise_dx += - 8.0 * t22 * t2 * x2 * graddotp3(gx2, gy2, gz2, x2, y2, z2) + t42 * gx2;
*    * dnoise_dy += - 8.0 * t22 * t2 * y2 * graddotp3(gx2, gy2, gz2, x2, y2, z2) + t42 * gy2;
*    * dnoise_dz += - 8.0 * t22 * t2 * z2 * graddotp3(gx2, gy2, gz2, x2, y2, z2) + t42 * gz2;
*    * dnoise_dx += - 8.0 * t23 * t3 * x3 * graddotp3(gx3, gy3, gz3, x3, y3, z3) + t43 * gx3;
*    * dnoise_dy += - 8.0 * t23 * t3 * y3 * graddotp3(gx3, gy3, gz3, x3, y3, z3) + t43 * gy3;
*    * dnoise_dz += - 8.0 * t23 * t3 * z3 * graddotp3(gx3, gy3, gz3, x3, y3, z3) + t43 * gz3;
*/
Float:temp0 = t20 * t0 * graddotp3(gx0, gy0, gz0, x0, y0, z0);
dnoise_dx = temp0 * x0;
dnoise_dy = temp0 * y0;
dnoise_dz = temp0 * z0;
Float:temp1 = t21 * t1 * graddotp3(gx1, gy1, gz1, x1, y1, z1);
dnoise_dx += temp1 * x1;
dnoise_dy += temp1 * y1;
dnoise_dz += temp1 * z1;
Float:temp2 = t22 * t2 * graddotp3(gx2, gy2, gz2, x2, y2, z2);
dnoise_dx += temp2 * x2;
dnoise_dy += temp2 * y2;
dnoise_dz += temp2 * z2;
Float:temp3 = t23 * t3 * graddotp3(gx3, gy3, gz3, x3, y3, z3);
dnoise_dx += temp3 * x3;
dnoise_dy += temp3 * y3;
dnoise_dz += temp3 * z3;
dnoise_dx *= - 8.0;
dnoise_dy *= - 8.0;
dnoise_dz *= - 8.0;
/* This corrects a bug in the original implementation */
dnoise_dx += t40 * gx0 + t41 * gx1 + t42 * gx2 + t43 * gx3;
dnoise_dy += t40 * gy0 + t41 * gy1 + t42 * gy2 + t43 * gy3;
dnoise_dz += t40 * gz0 + t41 * gz1 + t42 * gz2 + t43 * gz3;
dnoise_dx *= 28.0; /* Scale derivative to match the noise scaling */
dnoise_dy *= 28.0;
dnoise_dz *= 28.0;

return vec4(noise, dnoise_dx, dnoise_dy, dnoise_dz);
}

vec2 curlNoise(const vec2 &v)
{
const vec3 derivative = dnoise(v);
return vec2(derivative.z, - derivative.y);
}
vec2 curlNoise(const vec2 &v, Float:t)
{
const vec3 derivative = dFlowNoise(v, t);
return vec2(derivative.z, - derivative.y);
}
vec2 curlNoise(const vec2 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
const vec3 derivative = dfBm(v, octaves, lacunarity, gain);
return vec2(derivative.z, - derivative.y);
}
vec3 curlNoise(const vec3 &v)
{
const vec4 derivX = dnoise(v);
const vec4 derivY = dnoise(v + vec3(123.456, 789.012, 345.678));
const vec4 derivZ = dnoise(v + vec3(901.234, 567.891, 234.567));
return vec3(derivZ.z - derivY.w, derivX.w - derivZ.y, derivY.y - derivX.z);
}
vec3 curlNoise(const vec3 &v, Float:t)
{
const vec4 derivX = dFlowNoise(v, t);
const vec4 derivY = dFlowNoise(v + vec3(123.456, 789.012, 345.678), t);
const vec4 derivZ = dFlowNoise(v + vec3(901.234, 567.891, 234.567), t);
return vec3(derivZ.z - derivY.w, derivX.w - derivZ.y, derivY.y - derivX.z);
}
vec3 curlNoise(const vec3 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
const vec4 derivX = dfBm(v, octaves, lacunarity, gain);
const vec4 derivY = dfBm(v + vec3(123.456, 789.012, 345.678), octaves, lacunarity, gain);
const vec4 derivZ = dfBm(v + vec3(901.234, 567.891, 234.567), octaves, lacunarity, gain);
return vec3(derivZ.z - derivY.w, derivX.w - derivZ.y, derivY.y - derivX.z);
}

vec2 curl(const vec2 &v, const std::function < float(const vec2&)> &potential, Float:delta)
{
const vec2 deltaX = vec2(delta, 0.0);
const vec2 deltaY = vec2(0.0, delta);
return vec2(-(potential(v + deltaY) - potential(v - deltaY)),
(potential(v + deltaX) - potential(v - deltaX))) / (2.0 * delta);
}
vec3 curl(const vec3 &v, const std::function < vec3(const vec3&)> &potential, Float:delta)
{
const vec3 deltaX = vec3(delta, 0.0, 0.0);
const vec3 deltaY = vec3(0.0, delta, 0.0);
const vec3 deltaZ = vec3(0.0, 0.0, delta);
return vec3(((potential(v + deltaY).z - potential(v - deltaY).z)
-(potential(v + deltaZ).y - potential(v - deltaZ).y)),
((potential(v + deltaZ).x - potential(v - deltaZ).x)
-(potential(v + deltaX).z - potential(v - deltaX).z)),
((potential(v + deltaX).y - potential(v - deltaX).y)
-(potential(v + deltaY).x - potential(v - deltaY).x))) / (2.0 * delta);
}

Float:fBm(Float:x, uint8_t octaves, Float:lacunarity, Float:gain)
{
    Float:sum   = 0.0;
    Float:freq  = 1.0;
    Float:amp   = 0.5;

    for(uint8_t i = 0; i < octaves; i ++){
    Float:n     = noise(input * freq);
    sum        += n * amp;
    freq       *= lacunarity;
    amp        *= gain;
    }

    return sum;
}
Float:fBm(const vec2 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
    Float:sum   = 0.0;
    Float:freq  = 1.0;
    Float:amp   = 0.5;

    for(uint8_t i = 0; i < octaves; i ++){
    Float:n     = noise(input * freq);
    sum        += n * amp;
    freq       *= lacunarity;
    amp        *= gain;
    }

    return sum;
}
Float:fBm(const vec3 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
    Float:sum   = 0.0;
    Float:freq  = 1.0;
    Float:amp   = 0.5;

    for(uint8_t i = 0; i < octaves; i ++){
    Float:n     = noise(input * freq);
    sum        += n * amp;
    freq       *= lacunarity;
    amp        *= gain;
    }

    return sum;
}
Float:fBm(const vec4 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
    Float:sum   = 0.0;
    Float:freq  = 1.0;
    Float:amp   = 0.5;

    for(uint8_t i = 0; i < octaves; i ++){
    Float:n     = noise(input * freq);
    sum        += n * amp;
    freq       *= lacunarity;
    amp        *= gain;
    }

    return sum;
}

namespace details {
template < typename T>
Float:worleyfBm_t(const T &input, uint8_t octaves, Float:lacunarity, Float:gain)
{
Float:sum   = 0.0;
Float:freq  = 1.0;
Float:amp   = 0.5;

for(uint8_t i = 0; i < octaves; i ++){
Float:n     = worleyNoise(input * freq);
sum        += n * amp;
freq       *= lacunarity;
amp        *= gain;
}

return sum;
}
template < typename T>
Float:worleyfBm_t(const T &input, Float:falloff, uint8_t octaves, Float:lacunarity, Float:gain)
{
Float:sum   = 0.0;
Float:freq  = 1.0;
Float:amp   = 0.5;

for(uint8_t i = 0; i < octaves; i ++){
Float:n     = worleyNoise(input * freq, falloff);
sum        += n * amp;
freq       *= lacunarity;
amp        *= gain;
}

return sum;
}
}

Float:worleyfBm(const vec2 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
return worleyfBm_t(v, octaves, lacunarity, gain);
}
Float:worleyfBm(const vec3 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
return worleyfBm_t(v, octaves, lacunarity, gain);
}
Float:worleyfBm(const vec2 &v, Float:falloff, uint8_t octaves, Float:lacunarity, Float:gain)
{
return worleyfBm_t(v, falloff, octaves, lacunarity, gain);
}
Float:worleyfBm(const vec3 &v, Float:falloff, uint8_t octaves, Float:lacunarity, Float:gain)
{
return worleyfBm_t(v, falloff, octaves, lacunarity, gain);
}

vec2 dfBm(Float:x, uint8_t octaves, Float:lacunarity, Float:gain)
{
vec2 sum	= vec2(0.0);
Float:freq		= 1.0;
Float:amp		= 0.5;

for(uint8_t i = 0; i < octaves; i ++){
vec2 n	= dnoise(x * freq);
sum        += n * amp;
freq       *= lacunarity;
amp        *= gain;
}

return sum;
}
vec3 dfBm(const vec2 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
vec3 sum	= vec3(0.0);
Float:freq		= 1.0;
Float:amp		= 0.5;

for(uint8_t i = 0; i < octaves; i ++){
vec3 n	= dnoise(v * freq);
sum        += n * amp;
freq       *= lacunarity;
amp        *= gain;
}

return sum;
}
vec4 dfBm(const vec3 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
vec4 sum	= vec4(0.0);
Float:freq		= 1.0;
Float:amp		= 0.5;

for(uint8_t i = 0; i < octaves; i ++){
vec4 n	= dnoise(v * freq);
sum        += n * amp;
freq       *= lacunarity;
amp        *= gain;
}

return sum;
}
vec5 dfBm(const vec4 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
vec5 sum = { 0.0, 0.0, 0.0, 0.0, 0.0 };
Float:freq  = 1.0;
Float:amp   = 0.5;

for(uint8_t i = 0; i < octaves; i ++){
vec5 n = dnoise(v * freq);
sum[0]			+= n[0]* amp;
sum[1]			+= n[1]* amp;
sum[2]			+= n[2]* amp;
sum[3]			+= n[3]* amp;
sum[4]			+= n[4]* amp;
freq			*= lacunarity;
amp				*= gain;
}

return sum;
}



Float:ridge(Float:h, Float:offset)
{
    h = offset - floatabs(h);
    return h * h;
}

Float:ridgedMF_t(const T &input, Float:ridgeOffset, uint8_t octaves, Float:lacunarity, Float:gain)
{
    Float:sum	= 0;
    Float:freq	= 1.0;
    Float:amp	= 0.5;
    Float:prev	= 1.0;

    for(uint8_t i = 0; i < octaves; i ++){
        Float:n	= ridge(noise(input * freq), ridgeOffset);
        sum		+= n * amp * prev;
        prev	= n;
        freq	*= lacunarity;
        amp		*= gain;
    }
    return sum;
}

Float:ridgedMF(Float:x, Float:ridgeOffset, uint8_t octaves, Float:lacunarity, Float:gain)
{
return ridgedMF_t(x, ridgeOffset, octaves, lacunarity, gain);
}
Float:ridgedMF(const vec2 &v, Float:ridgeOffset, uint8_t octaves, Float:lacunarity, Float:gain)
{
return ridgedMF_t(v, ridgeOffset, octaves, lacunarity, gain);
}
Float:ridgedMF(const vec3 &v, Float:ridgeOffset, uint8_t octaves, Float:lacunarity, Float:gain)
{
return ridgedMF_t(v, ridgeOffset, octaves, lacunarity, gain);
}
Float:ridgedMF(const vec4 &v, Float:ridgeOffset, uint8_t octaves, Float:lacunarity, Float:gain)
{
return ridgedMF_t(v, ridgeOffset, octaves, lacunarity, gain);
}



Float:iqfBm(const vec2 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
Float:sum	= 0.0;
Float:amp	= 0.5;
Float:dx	= 0.0;
Float:dy	= 0.0;
Float:freq	= 1.0;
for(uint8_t i = 0; i < octaves; i ++) {
vec3 d = dnoise(v * freq);
dx += d.y;
dy += d.y;
sum += amp * d.x / (1.0 + dx * dx + dy * dy);
freq *= lacunarity;
amp *= gain;
}

return sum;
}
Float:iqfBm(const vec3 &v, uint8_t octaves, Float:lacunarity, Float:gain)
{
Float:sum	= 0.0;
Float:amp	= 0.5;
Float:dx	= 0.0;
Float:dy	= 0.0;
Float:dz	= 0.0;
Float:freq	= 1.0;
for(uint8_t i = 0; i < octaves; i ++) {
vec4 d = dnoise(v * freq);
dx += d.y;
dy += d.y;
dz += d.z;
sum += amp * d.x / (1.0 + dx * dx + dy * dy + d.z * d.z);
freq *= lacunarity;
amp *= gain;
}

return sum;
}

Float:iqMatfBm(const vec2 &v, uint8_t octaves, const mat2 &mat, Float:gain)
{
Float:sum		= 0.0;
Float:amp		= 1.0;
vec2 pos		= v;
vec2 noiseAccum	= vec2(0.0);
for(int i = 0; i < octaves; i ++){
vec3 n	= dnoise(pos);
noiseAccum	+= vec2(n.y, n.z);
sum			+= amp * n.x / (1.0 + dot(noiseAccum, noiseAccum));
amp			*= gain;
pos			= mat * pos;
}
return sum;
}
	
