////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2015 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_GLSL_HPP
#define SFML_GLSL_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <algorithm>


namespace sf
{
namespace priv
{

    ////////////////////////////////////////////////////////////
    /// \brief Matrix type, used to set uniforms in GLSL
    ///
    ////////////////////////////////////////////////////////////
    template <std::size_t Columns, std::size_t Rows>
    struct Matrix
    {
        ////////////////////////////////////////////////////////////
        /// \brief Constructor
        ///
        /// \param pointer Points to the beginning of an array that
        ///                has the size of the matrix. The elements
        ///                are copied to the instance.
        ///
        ////////////////////////////////////////////////////////////
        explicit Matrix(const float* pointer)
        {
            std::copy(pointer, pointer + Columns * Rows, array);
        }

        float array[Columns * Rows]; ///< Array holding matrix data
    };

    ////////////////////////////////////////////////////////////
    /// \brief 4D vector type, used to set uniforms in GLSL
    ///
    ////////////////////////////////////////////////////////////
    template <typename T>
    struct Vector4
    {
        ////////////////////////////////////////////////////////////
        /// \brief Default constructor, creates a zero vector
        ///
        ////////////////////////////////////////////////////////////
        Vector4() :
        x(0),
        y(0),
        z(0),
        w(0)
        {
        }

        ////////////////////////////////////////////////////////////
        /// \brief Construct from 4 vector components
        ///
        /// \param X,Y,Z,W Components of the 4D vector
        ///
        ////////////////////////////////////////////////////////////
        Vector4(T X, T Y, T Z, T W) :
        x(X),
        y(Y),
        z(Z),
        w(W)
        {
        }

        ////////////////////////////////////////////////////////////
        /// \brief Conversion constructor
        ///
        /// \param other 4D vector of different type
        ///
        ////////////////////////////////////////////////////////////
        template <typename U>
        explicit Vector4(const Vector4<U>& other) :
        x(static_cast<T>(other.x)),
        y(static_cast<T>(other.y)),
        z(static_cast<T>(other.z)),
        w(static_cast<T>(other.w))
        {
        }

        T x; ///< 1st component (X) of the 4D vector
        T y; ///< 2nd component (Y) of the 4D vector
        T z; ///< 3rd component (Z) of the 4D vector
        T w; ///< 4th component (W) of the 4D vector
    };

}


////////////////////////////////////////////////////////////
/// \brief Namespace with GLSL types
///
////////////////////////////////////////////////////////////
namespace Glsl
{

    ////////////////////////////////////////////////////////////
    /// \brief 3x3 float matrix (mat3 in GLSL)
    ///
    ////////////////////////////////////////////////////////////
    typedef priv::Matrix<3, 3> Mat3;

    ////////////////////////////////////////////////////////////
    /// \brief 4x4 float matrix (mat4 in GLSL)
    ///
    ////////////////////////////////////////////////////////////
    typedef priv::Matrix<4, 4> Mat4;

    ////////////////////////////////////////////////////////////
    /// \brief 2D float vector (vec2 in GLSL)
    ///
    ////////////////////////////////////////////////////////////
    typedef Vector2<float> Vec2;

    ////////////////////////////////////////////////////////////
    /// \brief 2D int vector (ivec2 in GLSL)
    ///
    ////////////////////////////////////////////////////////////
    typedef Vector2<int> Ivec2;

    ////////////////////////////////////////////////////////////
    /// \brief 2D bool vector (bvec2 in GLSL)
    ///
    ////////////////////////////////////////////////////////////
    typedef Vector2<bool> Bvec2;

    ////////////////////////////////////////////////////////////
    /// \brief 3D float vector (vec3 in GLSL)
    ///
    ////////////////////////////////////////////////////////////
    typedef Vector3<float> Vec3;

    ////////////////////////////////////////////////////////////
    /// \brief 3D int vector (ivec3 in GLSL)
    ///
    ////////////////////////////////////////////////////////////
    typedef Vector3<int> Ivec3;

    ////////////////////////////////////////////////////////////
    /// \brief 3D bool vector (bvec3 in GLSL)
    ///
    ////////////////////////////////////////////////////////////
    typedef Vector3<bool> Bvec3;

    ////////////////////////////////////////////////////////////
    /// \brief 4D float vector (vec4 in GLSL)
    ///
    ////////////////////////////////////////////////////////////
    typedef priv::Vector4<float> Vec4;

    ////////////////////////////////////////////////////////////
    /// \brief 4D int vector (ivec4 in GLSL)
    ///
    ////////////////////////////////////////////////////////////
    typedef priv::Vector4<int> Ivec4;

    ////////////////////////////////////////////////////////////
    /// \brief 4D bool vector (bvec4 in GLSL)
    ///
    ////////////////////////////////////////////////////////////
    typedef priv::Vector4<bool> Bvec4;

} // namespace Glsl
} // namespace sf


#endif // SFML_GLSL_HPP


////////////////////////////////////////////////////////////
/// \namespace sf::Glsl
/// \ingroup graphics
///
/// \details The sf::Glsl namespace contains types that match
/// their equivalents in GLSL, the OpenGL shading language.
/// These types are exclusively used by the sf::Shader class.
///
/// Types that already exist in SFML, such as \ref sf::Vector2<T>
/// and \ref sf::Vector3<T>, are reused as typedefs, so you can use
/// the types in this namespace as well as the original ones.
/// Others are newly defined, such as Vec4 or Mat3. Their actual
/// type is an implementation detail and should not be used.
///
/// All vector types support a default constructor that
/// initializes every component to zero, in addition to a
/// constructor with one parameter for each component.
/// The components are stored in member variables called
/// x, y, z, and w.
///
/// All matrix types support a constructor with a float*
/// parameter that points to a float array of the appropriate
/// size (that is, 9 in a 3x3 matrix, 16 in a 4x4 matrix).
///
/// \see sf::Shader
///
////////////////////////////////////////////////////////////
