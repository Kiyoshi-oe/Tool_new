import { ResourceItem } from "../../types/fileTypes";
import { ChevronDown, Info } from "lucide-react";
import { Input } from "../ui/input";
import { FormField } from "../ui/form-field";
import ModernToggle from "../ModernToggle";

interface PropertiesSectionProps {
  localItem: ResourceItem;
  editMode: boolean;
  handleDataChange: (field: string, value: string | number | boolean) => void;
}

const PropertiesSection = ({ localItem, editMode, handleDataChange }: PropertiesSectionProps) => {
  return (
    <div className="mb-6">
      <h2 className="text-cyrus-blue text-lg font-semibold mb-2">Additional Properties</h2>
      <div className="grid grid-cols-2 gap-4">

        
        <FormField
          id="durability"
          label="Durability"
          type="number"
          value={localItem.data.dwEndurance as string || '0'}
          onChange={(value) => handleDataChange('dwEndurance', value)}
          disabled={!editMode}
          helperText="Item durability"
        />
        
        <FormField
          id="max-repair"
          label="Max Repair"
          type="number"
          value={localItem.data.nMaxRepair as string || '0'}
          onChange={(value) => handleDataChange('nMaxRepair', value)}
          disabled={!editMode}
          helperText="Maximum number of times the item can be repaired"
        />
        
        <FormField
          id="handed"
          label="Handed"
          type="select"
          value={localItem.data.dwHanded as string || ''}
          onChange={(value) => handleDataChange('dwHanded', value)}
          disabled={!editMode}
          options={[
            { value: "HD_ONE", label: "One Hand" },
            { value: "HD_TWO", label: "Two Hand" }
          ]}
          helperText="Whether the item is one-handed or two-handed"
        />
        
        <FormField
          id="parts"
          label="Parts"
          type="select"
          value={localItem.data.dwParts as string || ''}
          onChange={(value) => handleDataChange('dwParts', value)}
          disabled={!editMode}
          options={[
            { value: "PARTS_RWEAPON", label: "Right Weapon" },
            { value: "PARTS_LWEAPON", label: "Left Weapon" },
            { value: "PARTS_HEAD", label: "Head" },
            { value: "PARTS_UPPER", label: "Upper Body" },
            { value: "PARTS_LOWER", label: "Lower Body" },
            { value: "PARTS_HAND", label: "Hands" },
            { value: "PARTS_FOOT", label: "Feet" }
          ]}
          helperText="Body part where the item is equipped"
        />
        
        <FormField
          id="item-level"
          label="Item Level"
          type="number"
          value={localItem.data.dwItemLV as string || '0'}
          onChange={(value) => handleDataChange('dwItemLV', value)}
          disabled={!editMode}
          helperText="Level requirement to use this item"
        />
        
        <div className="col-span-2 grid grid-cols-2 gap-4">
          <div className="form-field">
            <label className="form-label">Shop-able</label>
            <div className="mt-2">
              <ModernToggle
                value={localItem.data.dwShopAble === "1"}
                onChange={(value) => handleDataChange('dwShopAble', value ? "1" : "0")}
                falseLabel="No"
                trueLabel="Yes"
                disabled={!editMode}
              />
            </div>
            <p className="text-sm text-muted-foreground flex items-center gap-1 mt-1">
              <Info size={14} />
              <span>Whether the item can be sold in shops</span>
            </p>
          </div>

          <div className="form-field">
            <label className="form-label">Can Trade</label>
            <div className="mt-2">
              <ModernToggle
                value={localItem.data.bCanTrade === "1"}
                onChange={(value) => handleDataChange('bCanTrade', value ? "1" : "0")}
                falseLabel="No"
                trueLabel="Yes"
                disabled={!editMode}
              />
            </div>
            <p className="text-sm text-muted-foreground flex items-center gap-1 mt-1">
              <Info size={14} />
              <span>Whether the item can be traded between players</span>
            </p>
          </div>
        </div>
      </div>
    </div>
  );
};

export default PropertiesSection;
