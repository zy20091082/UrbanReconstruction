/******************************************************************************
 * $Id: reader10.hpp 751 2008-05-21 06:52:28Z mloskot $
 *
 * Project:  libLAS - http://liblas.org - A BSD library for LAS format data.
 * Purpose:  LAS 1.0 reader implementation for C++ libLAS 
 * Author:   Mateusz Loskot, mateusz@loskot.net
 *
 ******************************************************************************
 * Copyright (c) 2008, Mateusz Loskot
 *
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following 
 * conditions are met:
 * 
 *     * Redistributions of source code must retain the above copyright 
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright 
 *       notice, this list of conditions and the following disclaimer in 
 *       the documentation and/or other materials provided 
 *       with the distribution.
 *     * Neither the name of the Martin Isenburg or Iowa Department 
 *       of Natural Resources nor the names of its contributors may be 
 *       used to endorse or promote products derived from this software 
 *       without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS 
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 ****************************************************************************/

#ifndef LIBLAS_DETAIL_READER10_HPP_INCLUDED
#define LIBLAS_DETAIL_READER10_HPP_INCLUDED

#include <liblas/detail/reader.hpp>
#include <liblas/detail/fwd.hpp>
// std
#include <iosfwd>

namespace liblas { namespace detail { namespace v10 {

class ReaderImpl : public Reader
{
public:

    typedef Reader Base;
    
    ReaderImpl(std::istream& ifs);
    std::size_t GetVersion() const;
    bool ReadHeader(LASHeader& header);
    bool ReadNextPoint(PointRecord& record);
    bool ReadNextPoint(PointRecord& record, double& time);
    bool ReadPointAt(std::size_t n, PointRecord& record);
    bool ReadPointAt(std::size_t n, PointRecord& record, double& time);
    bool ReadVLR(LASHeader& header);
    bool ReadGeoreference(LASHeader& header); 
    std::istream& GetStream() const;

private:

    std::istream& m_ifs;
};

}}} // namespace liblas::detail::v10

#endif // LIBLAS_DETAIL_READER10_HPP_INCLUDED
