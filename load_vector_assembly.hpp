#pragma once
#include <Eigen/Core>
#include "load_vector.hpp"

//----------------AssembleVectorBegin----------------
//! Assemble the load vector into the full right hand side
//! for the linear system
//!
//! @param[out] F will at the end contain the RHS values for each vertex.
//! @param[in] vertices a list of triangle vertices
//! @param[in] triangles a list of triangles
//! @param[in] f the RHS function f.
void assembleLoadVector(Eigen::VectorXd& F,
                           const Eigen::MatrixXd& vertices,
                           const Eigen::MatrixXi& triangles,
                           const std::function<double(double, double)>& f)
{
     const int numberOfElements = triangles.rows();

     F.resize(vertices.rows());
     F.setZero();

     for(int m=0; m<numberOfElements; m++){
          auto& indexSet = triangles.row(m);

          const auto& a = vertices.row(indexSet(0));
          const auto& b = vertices.row(indexSet(1));
          const auto& c = vertices.row(indexSet(2));
          Eigen::Vector3d Load;
          computeLoadVector(Load,a,b,c,f);
          for( int alpha=0; alpha<3; alpha++){
               F(indexSet(alpha)) += Load(alpha);
          }
     }

}
//----------------AssembleVectorEnd----------------
