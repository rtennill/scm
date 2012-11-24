// Copyright (C) 2011-2012 Robert Kooima
//
// LIBSCM is free software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation; either version 2 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITH-
// OUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.

#ifndef SCM_TASK_HPP
#define SCM_TASK_HPP

#include <GL/glew.h>
#include <tiffio.h>

#include "scm-item.hpp"

//------------------------------------------------------------------------------

class scm_file;

//------------------------------------------------------------------------------

struct scm_task : public scm_item
{
    scm_task()                   : scm_item(    ), u(0), d(false), p(0) { }
    scm_task(int f, long long i) : scm_item(i, f), u(0), d(false), p(0) { }
    scm_task(int f, long long i, uint64 o, GLuint u, GLsizei s);

    void make_page(int, int, uint32, uint32, uint16, uint16, uint16);
    void load_page(scm_file *);
    void dump_page();

    uint64 o;          // SCM TIFF file offset of this page
    GLuint u;          // Pixel unpack buffer object
    bool   d;          // Pixel unpack buffer dirty flag
    void  *p;          // Pixel unpack buffer map address
};

//------------------------------------------------------------------------------

GLuint scm_internal_form(uint16, uint16, uint16);
GLuint scm_external_form(uint16, uint16, uint16);
GLuint scm_external_type(uint16, uint16, uint16);

//------------------------------------------------------------------------------

#endif
