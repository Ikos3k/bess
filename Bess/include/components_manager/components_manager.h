#pragma once
#include <string>
#include <unordered_map>
#include <vector>

#include "components/component.h"
#include "components_manager/component_bank.h"
#include "uuid.h"

#include <memory>

namespace Bess::Simulator {
    typedef std::shared_ptr<Components::Component> ComponentPtr;
    typedef std::unordered_map<uuids::uuid, ComponentPtr> TComponents;

    class ComponentsManager {
      public:
        static void init();

        // contains all the components that can be interacted with by user.
        static TComponents components;

        // contains all the components whose render function needs to be called from
        // scene.
        static std::vector<uuids::uuid> renderComponents;

        static void generateComponent(const ComponentBankElement &comp, const glm::vec3 &pos = {0.f, 0.f, 0.f});

        static void generateComponent(ComponentType type, const std::any &data = NULL, const glm::vec3 &pos = {0.f, 0.f, 0.f});

        static void deleteComponent(uuids::uuid uid);

        static uuids::uuid addConnection(const uuids::uuid &start, const uuids::uuid &end);

        static const uuids::uuid &renderIdToCid(int rId);

        static bool isRenderIdPresent(int rId);

        static int compIdToRid(const uuids::uuid &cid);

        static uuids::uuid emptyId;

        static int emptyRenderId;

        static const float zIncrement;

        static void addRenderIdToCId(int rid, const uuids::uuid &cid);

        static void addCompIdToRId(int rid, const uuids::uuid &cid);

        static void addSlotsToConn(const uuids::uuid &inpSlot, const uuids::uuid &outSlot, const uuids::uuid &conn);

        static const uuids::uuid &getConnectionBetween(const uuids::uuid &inpSlot, const uuids::uuid &outSlot);
        static const uuids::uuid &getConnectionBetween(const std::string &inputOutputSlot);

        static void removeSlotsToConn(const uuids::uuid &inpSlot, const uuids::uuid &outSlot);

        static const std::string &getSlotsForConnection(const uuids::uuid &conn);

        static float getNextZPos();

        static int getNextRenderId();
        static int getCurrentRenderId();

        static void reset();

        static std::shared_ptr<Components::Component> getComponent(const uuids::uuid &cid);

        template <typename T>
        static std::shared_ptr<T> getComponent(const uuids::uuid &cid) {
            return std::dynamic_pointer_cast<T>(components.at(cid));
        }

        static bool isRenderComponent(int rId);

      private:
        // mapping from render id to components id.
        static std::unordered_map<int, uuids::uuid> m_renderIdToCId;

        // mapping from component id to render id.
        static std::unordered_map<uuids::uuid, int> m_compIdToRId;

        // mapping for slots and correspondin connection id
        static std::unordered_map<std::string, uuids::uuid> m_slotsToConn;

        static int renderIdCounter;

        static float zPos;
    };
} // namespace Bess::Simulator
