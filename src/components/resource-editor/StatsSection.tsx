import { ResourceItem } from "../../types/fileTypes";
import { effectTypes } from "../../utils/resourceEditorUtils";
import React, { useState, useEffect } from "react";
import { Input } from "../ui/input";
import { Info } from "lucide-react";

interface StatsSectionProps {
  localItem: ResourceItem;
  editMode: boolean;
  handleDataChange: (field: string, value: string) => void;
}

const StatsSection = ({ localItem, editMode, handleDataChange }: StatsSectionProps) => {
  // Helper function to convert "=" to empty strings and vice versa
  const normalizeValue = (value: any): string => {
    return value === "=" ? "" : String(value || "");
  };

  // State for all 6 effects
  const [effects, setEffects] = useState<Array<{type: string, value: string}>>([
    { type: normalizeValue(localItem.data.dwDestParam1), value: normalizeValue(localItem.data.nAdjParamVal1) },
    { type: normalizeValue(localItem.data.dwDestParam2), value: normalizeValue(localItem.data.nAdjParamVal2) },
    { type: normalizeValue(localItem.data.dwDestParam3), value: normalizeValue(localItem.data.nAdjParamVal3) },
    { type: normalizeValue(localItem.data.dwDestParam4), value: normalizeValue(localItem.data.nAdjParamVal4) },
    { type: normalizeValue(localItem.data.dwDestParam5), value: normalizeValue(localItem.data.nAdjParamVal5) },
    { type: normalizeValue(localItem.data.dwDestParam6), value: normalizeValue(localItem.data.nAdjParamVal6) }
  ]);

  // Update state when item changes
  useEffect(() => {
    setEffects([
      { type: normalizeValue(localItem.data.dwDestParam1), value: normalizeValue(localItem.data.nAdjParamVal1) },
      { type: normalizeValue(localItem.data.dwDestParam2), value: normalizeValue(localItem.data.nAdjParamVal2) },
      { type: normalizeValue(localItem.data.dwDestParam3), value: normalizeValue(localItem.data.nAdjParamVal3) },
      { type: normalizeValue(localItem.data.dwDestParam4), value: normalizeValue(localItem.data.nAdjParamVal4) },
      { type: normalizeValue(localItem.data.dwDestParam5), value: normalizeValue(localItem.data.nAdjParamVal5) },
      { type: normalizeValue(localItem.data.dwDestParam6), value: normalizeValue(localItem.data.nAdjParamVal6) }
    ]);
  }, [localItem]);

  // Handler for effect type changes
  const handleEffectTypeChange = (index: number, newType: string) => {
    if (!editMode) return;

    const newEffects = [...effects];
    newEffects[index] = {
      ...newEffects[index],
      type: newType
    };
    setEffects(newEffects);

    // Update the corresponding dwDestParam field
    // Convert empty values back to "=" when saving
    handleDataChange(`dwDestParam${index + 1}`, newType || "=");
  };

  // Handler for effect value changes
  const handleEffectValueChange = (index: number, newValue: string) => {
    if (!editMode) return;

    const newEffects = [...effects];
    newEffects[index] = {
      ...newEffects[index],
      value: newValue
    };
    setEffects(newEffects);

    // Update the corresponding nAdjParamVal field
    // Convert empty values back to "=" when saving
    handleDataChange(`nAdjParamVal${index + 1}`, newValue || "=");
  };

  return (
    <div className="mb-6">
      <h2 className="text-cyrus-blue text-lg font-semibold mb-2">Stats</h2>
      
      {/* Basic Stats (Min/Max, Block Rating, Attack Speed) */}
      <div className="grid grid-cols-2 gap-3 mb-4">
        <div className="col-span-1">
          <label htmlFor="ability-min" className="text-sm font-medium mb-1 block">
            Min. Damage/Defense
          </label>
          <Input
            id="ability-min"
            type="text"
            value={String(localItem.data.dwAbilityMin || "")}
            onChange={(e: React.ChangeEvent<HTMLInputElement>) => {
              console.log("Changing dwAbilityMin to:", e.target.value);
              handleDataChange("dwAbilityMin", e.target.value);
            }}
            disabled={!editMode}
            placeholder="Min. Value"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
          <p className="text-sm text-muted-foreground flex items-center gap-1 mt-1">
            <Info size={14} />
            <span>Min. Ability Value (Damage/Defense)</span>
          </p>
        </div>
        
        <div className="col-span-1">
          <label htmlFor="ability-max" className="text-sm font-medium mb-1 block">
            Max. Damage/Defense
          </label>
          <Input
            id="ability-max"
            type="text"
            value={String(localItem.data.dwAbilityMax || "")}
            onChange={(e: React.ChangeEvent<HTMLInputElement>) => {
              console.log("Changing dwAbilityMax to:", e.target.value);
              handleDataChange("dwAbilityMax", e.target.value);
            }}
            disabled={!editMode}
            placeholder="Max. Value"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
          <p className="text-sm text-muted-foreground flex items-center gap-1 mt-1">
            <Info size={14} />
            <span>Max. Ability Value (Damage/Defense)</span>
          </p>
        </div>
      </div>

      {/* Block Rating and Attack Speed */}
      <div className="grid grid-cols-2 gap-3 mb-4">
        <div className="col-span-1">
          <label htmlFor="block-rating" className="text-sm font-medium mb-1 block">
            Block Rating
          </label>
          <Input
            id="block-rating"
            type="text"
            value={String(localItem.data.dwBlockRating || "")}
            onChange={(e: React.ChangeEvent<HTMLInputElement>) => {
              handleDataChange("dwBlockRating", e.target.value);
            }}
            disabled={!editMode}
            placeholder="Block Rating"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
          <p className="text-sm text-muted-foreground flex items-center gap-1 mt-1">
            <Info size={14} />
            <span>Die Blockrate des Gegenstands</span>
          </p>
        </div>
        
        <div className="col-span-1">
          <label htmlFor="attack-speed" className="text-sm font-medium mb-1 block">
            Angriffsgeschwindigkeit
          </label>
          <Input
            id="attack-speed"
            type="text"
            value={String(localItem.data.dwAttackSpeed || "")}
            onChange={(e: React.ChangeEvent<HTMLInputElement>) => {
              handleDataChange("dwAttackSpeed", e.target.value);
            }}
            disabled={!editMode}
            placeholder="Attack Speed"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
          <p className="text-sm text-muted-foreground flex items-center gap-1 mt-1">
            <Info size={14} />
            <span>Die Angriffsgeschwindigkeit des Gegenstands</span>
          </p>
        </div>
      </div>

      {/* Additional Skill Min/Max */}
      <div className="grid grid-cols-2 gap-3 mb-4">
        <div className="col-span-1">
          <label htmlFor="add-skill-min" className="text-sm font-medium mb-1 block">
            Min. Fähigkeitswert
          </label>
          <Input
            id="add-skill-min"
            type="text"
            value={String(localItem.data.dwAddSkillMin || "")}
            onChange={(e: React.ChangeEvent<HTMLInputElement>) => {
              handleDataChange("dwAddSkillMin", e.target.value);
            }}
            disabled={!editMode}
            placeholder="Min. Skill Value"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
          <p className="text-sm text-muted-foreground flex items-center gap-1 mt-1">
            <Info size={14} />
            <span>Zusätzlicher minimaler Fähigkeitswert</span>
          </p>
        </div>
        
        <div className="col-span-1">
          <label htmlFor="add-skill-max" className="text-sm font-medium mb-1 block">
            Max. Fähigkeitswert
          </label>
          <Input
            id="add-skill-max"
            type="text"
            value={String(localItem.data.dwAddSkillMax || "")}
            onChange={(e: React.ChangeEvent<HTMLInputElement>) => {
              handleDataChange("dwAddSkillMax", e.target.value);
            }}
            disabled={!editMode}
            placeholder="Max. Skill Value"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
          <p className="text-sm text-muted-foreground flex items-center gap-1 mt-1">
            <Info size={14} />
            <span>Zusätzlicher maximaler Fähigkeitswert</span>
          </p>
        </div>
      </div>
      
      {/* Row 1: Effect 1 | Value 1 | Effect 2 | Value 2 */}
      <div className="grid grid-cols-4 gap-3 mb-3">
        {/* Effect 1 */}
        <div className="col-span-1">
          <label htmlFor="effect-type-1" className="text-sm font-medium mb-1 block">
            Effect 1
          </label>
          <select
            id="effect-type-1"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
            value={effects[0].type}
            onChange={(e) => handleEffectTypeChange(0, e.target.value)}
            disabled={!editMode}
          >
            <option value="">(no effect)</option>
            {effectTypes.map(type => (
              <option key={type} value={type}>{type}</option>
            ))}
          </select>
        </div>
        
        {/* Value 1 */}
        <div className="col-span-1">
          <label htmlFor="effect-value-1" className="text-sm font-medium mb-1 block">
            &nbsp;
          </label>
          <Input
            id="effect-value-1"
            type="text"
            value={effects[0].value}
            onChange={(e) => handleEffectValueChange(0, e.target.value)}
            disabled={!editMode || !effects[0].type}
            placeholder="Value"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
        </div>
        
        {/* Effect 2 */}
        <div className="col-span-1">
          <label htmlFor="effect-type-2" className="text-sm font-medium mb-1 block">
            Effect 2
          </label>
          <select
            id="effect-type-2"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
            value={effects[1].type}
            onChange={(e) => handleEffectTypeChange(1, e.target.value)}
            disabled={!editMode}
          >
            <option value="">(no effect)</option>
            {effectTypes.map(type => (
              <option key={type} value={type}>{type}</option>
            ))}
          </select>
        </div>
        
        {/* Value 2 */}
        <div className="col-span-1">
          <label htmlFor="effect-value-2" className="text-sm font-medium mb-1 block">
            &nbsp;
          </label>
          <Input
            id="effect-value-2"
            type="text"
            value={effects[1].value}
            onChange={(e) => handleEffectValueChange(1, e.target.value)}
            disabled={!editMode || !effects[1].type}
            placeholder="Value"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
        </div>
      </div>
      
      {/* Row 2: Effect 3 | Value 3 | Effect 4 | Value 4 */}
      <div className="grid grid-cols-4 gap-3 mb-3">
        {/* Effect 3 */}
        <div className="col-span-1">
          <label htmlFor="effect-type-3" className="text-sm font-medium mb-1 block">
            Effect 3
          </label>
          <select
            id="effect-type-3"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
            value={effects[2].type}
            onChange={(e) => handleEffectTypeChange(2, e.target.value)}
            disabled={!editMode}
          >
            <option value="">(no effect)</option>
            {effectTypes.map(type => (
              <option key={type} value={type}>{type}</option>
            ))}
          </select>
        </div>
        
        {/* Value 3 */}
        <div className="col-span-1">
          <label htmlFor="effect-value-3" className="text-sm font-medium mb-1 block">
            &nbsp;
          </label>
          <Input
            id="effect-value-3"
            type="text"
            value={effects[2].value}
            onChange={(e) => handleEffectValueChange(2, e.target.value)}
            disabled={!editMode || !effects[2].type}
            placeholder="Value"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
        </div>
        
        {/* Effect 4 */}
        <div className="col-span-1">
          <label htmlFor="effect-type-4" className="text-sm font-medium mb-1 block">
            Effect 4
          </label>
          <select
            id="effect-type-4"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
            value={effects[3].type}
            onChange={(e) => handleEffectTypeChange(3, e.target.value)}
            disabled={!editMode}
          >
            <option value="">(no effect)</option>
            {effectTypes.map(type => (
              <option key={type} value={type}>{type}</option>
            ))}
          </select>
        </div>
        
        {/* Value 4 */}
        <div className="col-span-1">
          <label htmlFor="effect-value-4" className="text-sm font-medium mb-1 block">
            &nbsp;
          </label>
          <Input
            id="effect-value-4"
            type="text"
            value={effects[3].value}
            onChange={(e) => handleEffectValueChange(3, e.target.value)}
            disabled={!editMode || !effects[3].type}
            placeholder="Value"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
        </div>
      </div>
      
      {/* Row 3: Effect 5 | Value 5 | Effect 6 | Value 6 */}
      <div className="grid grid-cols-4 gap-3">
        {/* Effect 5 */}
        <div className="col-span-1">
          <label htmlFor="effect-type-5" className="text-sm font-medium mb-1 block">
            Effect 5
          </label>
          <select
            id="effect-type-5"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
            value={effects[4].type}
            onChange={(e) => handleEffectTypeChange(4, e.target.value)}
            disabled={!editMode}
          >
            <option value="">(no effect)</option>
            {effectTypes.map(type => (
              <option key={type} value={type}>{type}</option>
            ))}
          </select>
        </div>
        
        {/* Value 5 */}
        <div className="col-span-1">
          <label htmlFor="effect-value-5" className="text-sm font-medium mb-1 block">
            &nbsp;
          </label>
          <Input
            id="effect-value-5"
            type="text"
            value={effects[4].value}
            onChange={(e) => handleEffectValueChange(4, e.target.value)}
            disabled={!editMode || !effects[4].type}
            placeholder="Value"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
        </div>
        
        {/* Effect 6 */}
        <div className="col-span-1">
          <label htmlFor="effect-type-6" className="text-sm font-medium mb-1 block">
            Effect 6
          </label>
          <select
            id="effect-type-6"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
            value={effects[5].type}
            onChange={(e) => handleEffectTypeChange(5, e.target.value)}
            disabled={!editMode}
          >
            <option value="">(no effect)</option>
            {effectTypes.map(type => (
              <option key={type} value={type}>{type}</option>
            ))}
          </select>
        </div>
        
        {/* Value 6 */}
        <div className="col-span-1">
          <label htmlFor="effect-value-6" className="text-sm font-medium mb-1 block">
            &nbsp;
          </label>
          <Input
            id="effect-value-6"
            type="text"
            value={effects[5].value}
            onChange={(e) => handleEffectValueChange(5, e.target.value)}
            disabled={!editMode || !effects[5].type}
            placeholder="Value"
            className="w-full p-2 border border-gray-300 rounded focus:ring-blue-500 focus:border-blue-500"
          />
        </div>
      </div>
    </div>
  );
};

export default StatsSection;
