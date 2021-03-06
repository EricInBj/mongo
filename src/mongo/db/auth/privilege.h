/*    Copyright 2012 10gen Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include <string>

#include "mongo/db/auth/action_set.h"
#include "mongo/db/auth/action_type.h"
#include "mongo/db/auth/principal.h"

namespace mongo {

    /**
     * A representation of the permission to perform a set of actions on a specific resource.
     */
    class Privilege {
    public:

        Privilege(const std::string& resource, ActionSet actions);
        ~Privilege() {}

        const std::string& getResource() const { return _resource; }

        const ActionSet& getActions() const { return _actions; }

        // Checks if the given action is present in the Privilege.
        bool includesAction(const ActionType& action) const;

    private:

        std::string _resource;
        ActionSet _actions; // bitmask of actions this privilege grants
    };

} // namespace mongo
