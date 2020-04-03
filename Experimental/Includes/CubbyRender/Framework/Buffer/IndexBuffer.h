/*************************************************************************
> File Name: IndexBuffer.h
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: Abstract base class for IndexBuffer object.
> Created Time: 2020/03/16
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef CUBBYFLOW_INDEXBUFFER_H
#define CUBBYFLOW_INDEXBUFFER_H

#include <Framework/Utils/Prerequisites.h>
#include <Framework/Buffer/Buffer.h>
#include <Core/Array/Array1.h>
#include <Core/Array/ArrayAccessor1.h>
#include <memory>

namespace CubbyFlow {
namespace CubbyRender {
    
    //!
    //! \brief Abstract base class for Shader object.
    //!
    class IndexBuffer : public Buffer
    {
    public:
        //! Default constructor.
        IndexBuffer();

        //! Default destructor.
        virtual ~IndexBuffer();

        //! Allocate gpu 
        void allocateBuffer(RendererPtr renderer, const ConstArrayAccessor1<unsigned int>& data, size_t numberOfIndices);

        //! Update 
        virtual void updateBuffer(RendererPtr renderer, const ConstArrayAccessor1<unsigned int>& data) = 0;

        size_t getNumberOfIndices() const;

        void bindState(RendererPtr renderer);

    protected:
        //! implementation of bind method
        virtual void onBind(RendererPtr renderer) override = 0;
        
        //! implementation of unbind method
        virtual void onUnbind(RendererPtr renderer) override = 0;

        //! implementation of destry method
        virtual void onDestroy() override = 0;

        //! Allocate gpu 
        virtual void onAllocateBuffer(RendererPtr renderer, const ConstArrayAccessor1<unsigned int>& data) = 0;

        //! implementation of bind state method.
        virtual void onBindState(RendererPtr renderer) = 0;

        size_t _numberOfIndices;
    private:
    };

    using IndexBufferPtr = std::shared_ptr<IndexBuffer>;
} 
}

#endif