import { ResourceItem } from "../../types/fileTypes";
import { Input } from "../ui/input";
import { attackStyleOptions, weaponTypeOptions } from "../../utils/resourceEditorUtils";
import { FormField } from "../ui/form-field";

interface WeaponPropertiesSectionProps {
  localItem: ResourceItem;
  editMode: boolean;
  handleDataChange: (field: string, value: string | number | boolean) => void;
}

const WeaponPropertiesSection = ({ localItem, editMode, handleDataChange }: WeaponPropertiesSectionProps) => {
  if (localItem.data.dwItemKind1 !== "IK1_WEAPON") {
    return null;
  }

  return (
    <div className="mb-6">
      <h2 className="text-cyrus-blue text-lg font-semibold mb-2">Weapon Properties</h2>
      <div className="grid grid-cols-2 gap-4">
        <div className="form-field">
          <label className="form-label">Attack Min</label>
          <Input
            type="number"
            className="form-input"
            value={localItem.data.dwAbilityMin as string || '0'}
            onChange={(e) => handleDataChange('dwAbilityMin', e.target.value)}
            disabled={!editMode}
          />
        </div>
        
        <div className="form-field">
          <label className="form-label">Attack Max</label>
          <Input
            type="number"
            className="form-input"
            value={localItem.data.dwAbilityMax as string || '0'}
            onChange={(e) => handleDataChange('dwAbilityMax', e.target.value)}
            disabled={!editMode}
          />
        </div>
        
        <FormField
          id="attack-style-1"
          label="Attack Style 1"
          type="select"
          value={localItem.data.dwItemAtkOrder1 as string || ''}
          onChange={(value) => handleDataChange('dwItemAtkOrder1', value)}
          disabled={!editMode}
          options={attackStyleOptions}
        />
        
        <FormField
          id="attack-style-2"
          label="Attack Style 2"
          type="select"
          value={localItem.data.dwItemAtkOrder2 as string || ''}
          onChange={(value) => handleDataChange('dwItemAtkOrder2', value)}
          disabled={!editMode}
          options={attackStyleOptions}
        />
        
        <FormField
          id="weapon-type"
          label="Weapon Type"
          type="select"
          value={localItem.data.dwWeaponType as string || ''}
          onChange={(value) => handleDataChange('dwWeaponType', value)}
          disabled={!editMode}
          options={weaponTypeOptions}
        />
        
        <div className="form-field">
          <label className="form-label">Hit Rate Adjustment</label>
          <Input
            type="number"
            className="form-input"
            value={localItem.data.nAdjHitRate as string || '0'}
            onChange={(e) => handleDataChange('nAdjHitRate', e.target.value)}
            disabled={!editMode}
            step="0.01"
          />
        </div>
      </div>
    </div>
  );
};

export default WeaponPropertiesSection;
