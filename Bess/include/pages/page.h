#pragma once
#include "events/application_event.h"
#include "pages/page_identifier.h"
#include <memory>
#include <vector>

namespace Bess::Pages {
    class Page {
      public:
        virtual ~Page() = default;
        Page(PageIdentifier identifier);

        void show();
        PageIdentifier getIdentifier() const;

        virtual void draw() = 0;
        virtual void update(const std::vector<ApplicationEvent> &events) = 0;

      private:
        PageIdentifier m_identifier;
    };
} // namespace Bess::Pages
