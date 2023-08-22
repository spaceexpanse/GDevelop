// @flow
import * as React from 'react';
import {
  type Team,
  type TeamGroup,
  type User,
  type TeamMembership,
} from '../../Utils/GDevelopServices/User';
import { type CloudProjectWithUserAccessInfo } from '../../Utils/GDevelopServices/Project';

export type TeamState = {|
  team: ?Team,
  groups: ?Array<TeamGroup>,
  members: ?Array<User>,
  memberships: ?Array<TeamMembership>,
  onChangeGroupName: (group: TeamGroup, newName: string) => Promise<void>,
  onChangeUserGroup: (user: User, group: TeamGroup) => Promise<void>,
  onListUserProjects: (
    user: User
  ) => Promise<Array<CloudProjectWithUserAccessInfo>>,
|};

export const initialTeamState = {
  team: null,
  groups: null,
  members: null,
  memberships: null,
  onChangeGroupName: async () => {},
  onChangeUserGroup: async () => {},
  onListUserProjects: async () => [],
};

const TeamContext = React.createContext<TeamState>(initialTeamState);

export default TeamContext;
