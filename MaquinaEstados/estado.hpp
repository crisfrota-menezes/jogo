#pragma once

#include "../ente.hpp"

namespace SpaceHunt
{
    namespace Estados
    {
        class Estado : public Ente
        {
        private:
            bool remover;

        public:
            Estado(const IDs::IDs ID);
            ~Estado();
            virtual void executar() = 0;
            virtual void desenhar();
            const bool getRemover() const;
            void setRemover(const bool remover = true);
        };
    }
    using namespace Estados;
}
using namespace SpaceHunt;